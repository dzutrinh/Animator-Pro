
/* undone */
/* gel.c - Stuff to do the gel tool.  Basiccally concentric transparent
  circles with the wider ones thinner. */

#include "jimk.h"
#include "redo.h"
#include "errcodes.h"
#include "inks.h"
#include "broadcas.h"

extern void render_hline();

extern SHORT gel_factor;
static int gft[4] = {15*1, 16*2, 17*3, 18*4};
extern char *gel_thash;

static char *th[4];

static void zero_th(void)
{
int i;

for (i=0; i<4; i++)
	clear_mem(th[i], COLORS*2);
}
Errcode gel_tool_loop( Errcode (*get_posp)(Pos_p *pp, void *idata, SHORT mode),
					   void *idata)

/* for EFUNC non Success is end of input, its return is returned by this */
{
Errcode err;
int pw;
int pwt[4];
int i;
Pos_p rp;
Boolean ozoom;

	ozoom = vs.zoom_open;

	if((err = get_posp(&rp, idata, DT_GEL)) != Success)
		return(err);
	pw = 1 + vs.gel_brush_size;
	pwt[0] = pw*2;
	pwt[1] = pw*3/2;
	pwt[2] = pw;
	pwt[3] = pw/2;
	clear_mem(th, sizeof(th));
	set_full_gradrect();
	gel_factor = 1;		/* set this for make_render_cashes... */
	make_render_cashes();
	if (vs.ink_id == opq_INKID)	/* opaque ... can optimize */
	{
		for (i=0; i<4;i++)
		{
			if ((th[i] = pj_zalloc(COLORS*2)) == NULL)
			{
				err = Err_no_memory;
				goto error;
			}
		}
	}
	else
	{
		if (!is_bhash())
			make_bhash();
	}
	if ((err = start_line_undo()) < Success)
		goto error;
	set_full_gradrect();

	for (;;)
	{
		save_lines_undo(rp.y-pwt[0], (pwt[0]<<1)+1);
		for (i=0; i<4; i++)
		{
			gel_factor = gft[i];
			gel_thash = th[i];
			if((err = doval(rp.x,rp.y,(pwt[i]<<1)+1,
						    vb.pencel->aspect_dx, vb.pencel->aspect_dy,
				    		NULL,NULL,render_hline,vb.pencel,TRUE)) < Success)
			{
				goto error;	
			}
		}
		if (vs.cycle_draw)
		{
			cycle_ccolor();
			if (vs.ink_id == opq_INKID)
				zero_th();
			else
			{
				if (!is_bhash())
					make_bhash();
			}
		}
		if((err = get_posp(&rp, idata, DT_GEL)) != Success)
			break;
	}

error:
	end_line_undo();
	if (vs.ink_id == opq_INKID)
	{
		for (i=0; i<4; i++)
			pj_gentle_free(th[i]);
	}
	free_render_cashes();
	if (is_bhash())
		free_bhash();
	gel_factor = 0;
	if(vs.cycle_draw)
		do_color_redraw(NEW_CCOLOR);
	return(err);
}

Errcode gel_tool(void)
{
Errcode err;
extern Errcode dtool_input(Pos_p *p, void *dummy, SHORT mode);

	for (;;)
	{
		if (!pti_input())
			return(Success);
		reuse_input();
		if((err = start_save_redo_points())<Success)
			break;
		err = gel_tool_loop(dtool_input, NULL);
		end_save_redo_points();
		save_redo_gel();
	}
	return(err);
}

/**** seeme for gel option display ******/

static void seegb_dot(SHORT x,SHORT y,Raster *r)
{
	pj_put_dot(r,sgrey,x,y);
}
void see_gel_brush(Button *b)
{
int pw, i;
Clipbox cb;

	mb_make_clip(b,&cb);
	pw = 1 + vs.gel_brush_size;

	white_block(b);
	for (i = pw*4; i>0; i -= pw)
	{
		doval(b->width>>1,b->height>>1,i,
				cb.aspect_dx, cb.aspect_dy,
				seegb_dot,&cb,NULL,NULL,FALSE);
	}
}
