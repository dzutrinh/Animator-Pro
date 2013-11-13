
/* brush.c - definition of some bitmap shapes for menus and mouse cursor */

#include "jimk.h"
#include "flicmenu.h"


UBYTE default2_cursor[] = {
		0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 
		0x00,0x00, 0x00,0x00, 0x00,0x80, 0x00,0x00,
		0x02,0x20, 0x00,0x00, 0x00,0x80, 0x00,0x00, 
		0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,
		};

UBYTE default_cursor[] = {
		0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 
		0x00,0x80, 0x00,0x80, 0x00,0x00, 0x00,0x00,
		0x0c,0x18, 0x00,0x00, 0x00,0x00, 0x00,0x80, 
		0x00,0x80, 0x00,0x00, 0x00,0x00, 0x00,0x00,
		};


PLANEPTR white_cursor = (PLANEPTR)default_cursor,
	black_cursor = (PLANEPTR)default2_cursor;
