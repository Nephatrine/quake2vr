/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

// cl_util.c -- misc client utility functions

#include "client.h"

//=================================================

// Here I convert old 256 color palette to RGB
const byte default_pal[768] = {
#include "q2palette.h"
};


int32_t	color8red (int32_t color8)
{ 
	return (default_pal[color8*3+0]);
}


int32_t	color8green (int32_t color8)
{
	return (default_pal[color8*3+1]);;
}


int32_t	color8blue (int32_t color8)
{
	return (default_pal[color8*3+2]);;
}

//=================================================

void vectoangles (vec3_t value1, vec3_t angles)
{
	float	forward;
	float	yaw, pitch;
	
	if (value1[1] == 0 && value1[0] == 0)
	{
		yaw = 0;
		if (value1[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else
	{
		// PMM - fixed to correct for pitch of 0
		if (value1[0])
			yaw = (atan2(value1[1], value1[0]) * 180 / M_PI);
		else if (value1[1] > 0)
			yaw = 90;
		else
			yaw = 270;

		if (yaw < 0)
			yaw += 360;

		forward = sqrt (value1[0]*value1[0] + value1[1]*value1[1]);
		pitch = (atan2(value1[2], forward) * 180 / M_PI);
		if (pitch < 0)
			pitch += 360;
	}

	angles[PITCH] = -pitch;
	angles[YAW] = yaw;
	angles[ROLL] = 0;
}


void vectoangles2 (vec3_t value1, vec3_t angles)
{
	float	forward;
	float	yaw, pitch;
	
	if (value1[1] == 0 && value1[0] == 0)
	{
		yaw = 0;
		if (value1[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else
	{
	// PMM - fixed to correct for pitch of 0
		if (value1[0])
			yaw = (atan2(value1[1], value1[0]) * 180 / M_PI);
		else if (value1[1] > 0)
			yaw = 90;
		else
			yaw = 270;

		if (yaw < 0)
			yaw += 360;

		forward = sqrt (value1[0]*value1[0] + value1[1]*value1[1]);
		pitch = (atan2(value1[2], forward) * 180 / M_PI);
		if (pitch < 0)
			pitch += 360;
	}

	angles[PITCH] = -pitch;
	angles[YAW] = yaw;
	angles[ROLL] = 0;
}

/*
================
ColorLookup
Returns RGB values for color type, can be called from anywhere
================
*/
void ColorLookup (int32_t colornum, int32_t *red, int32_t *green, int32_t *blue)
{
	switch (colornum)
	{
	case COLOR_GRAY:		//gray
		*red =	155;
		*green=	155;
		*blue =	155;
		break;
	case COLOR_RED:		//red
		*red =	255;
		*green=	0;
		*blue =	0;
		break;
	case COLOR_GREEN:		//green
		*red =	0;
		*green=	255;
		*blue =	0;
		break;
	case COLOR_YELLOW:		//yellow
		*red =	255;
		*green=	255;
		*blue =	0;
		break;
	case COLOR_BLUE:		//blue
		*red =	0;
		*green=	0;
		*blue =	255;
		break;
	case COLOR_CYAN:		//cyan
		*red =	0;
		*green=	255;
		*blue =	255;
		break;
	case COLOR_MAGENTA:		//magenta
		*red =	255;
		*green=	0;
		*blue =	255;
		break;
	case COLOR_BLACK:		//black
		*red =	0;
		*green=	0;
		*blue =	0;
		break;
	case COLOR_ORANGE:		//orange
		*red =	255;
		*green=	135;
		*blue =	0;
		break;
	default:	//white
	case COLOR_WHITE:
		*red =	255;
		*green=	255;
		*blue =	255;
		break;
	}
}