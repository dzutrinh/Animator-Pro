; generated by gfxlib.c 


gfxl_pj_clipbox_make equ +014H
gfxl_close_raster equ +018H
gfxl_pj_rast_free equ +01cH
gfxl_put_hseg equ +020H
gfxl_get_hseg equ +024H
gfxl_put_vseg equ +028H
gfxl_get_vseg equ +02cH
gfxl_put_rectpix equ +030H
gfxl_get_rectpix equ +034H
gfxl_set_hline equ +038H
gfxl_set_vline equ +03cH
gfxl_pj_clear_rast equ +040H
gfxl_set_rect equ +044H
gfxl_xor_rect equ +048H
gfxl_mask1blit equ +04cH
gfxl_mask2blit equ +050H
gfxl_xor_rast equ +054H
gfxl__blitrect equ +058H
gfxl_blitrect equ +05cH
gfxl__tblitrect equ +060H
gfxl_tblitrect equ +064H
gfxl__swaprect equ +068H
gfxl_swaprect equ +06cH
gfxl_zoomblit equ +070H
gfxl_pj_cmap_alloc equ +074H
gfxl_pj_cmap_free equ +078H
gfxl_pj_cmap_load equ +07cH
gfxl_pj_cmap_copy equ +080H
gfxl_pj_rcel_bytemap_open equ +084H
gfxl_pj_rcel_bytemap_alloc equ +088H
gfxl_pj_rcel_make_virtual equ +08cH
gfxl_pj_rcel_close equ +090H
gfxl_pj_rcel_free equ +094H

; end gfxlib.c generated code

	EXTRN _a_a_gfxlib:word

; macro for jumping to _a_a_gfxlib calls

GFXLIB_JUMP MACRO PUBNAME,LIBCALL
	public PUBNAME
PUBNAME proc near
	mov eax,dword ptr _a_a_gfxlib
	jmp dword ptr LIBCALL[eax]
PUBNAME endp
	ENDM

