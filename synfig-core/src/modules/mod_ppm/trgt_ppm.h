/* === S Y N F I G ========================================================= */
/*!	\file trgt_ppm.h
**	\brief Template Header
**
**	$Id$
**
**	\legal
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
**
** === N O T E S ===========================================================
**
** ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_TRGT_PPM_H
#define __SYNFIG_TRGT_PPM_H

/* === H E A D E R S ======================================================= */

#include <synfig/target_scanline.h>
#include <synfig/string.h>
#include <synfig/smartfile.h>
#include <synfig/targetparam.h>
#include <cstdio>

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

class ppm : public synfig::Target_Scanline
{
	SYNFIG_TARGET_MODULE_EXT

private:
	int imagecount;
	bool multi_image;
	synfig::SmartFILE file;
	synfig::String filename;
	synfig::Color *color_buffer;
	unsigned char *buffer;
	unsigned char *rgba_buffer;
public:
	ppm(const char *filename, const synfig::TargetParam& /* params */);
	virtual ~ppm();

	virtual bool set_rend_desc(synfig::RendDesc *desc);
	virtual bool start_frame(synfig::ProgressCallback *cb);
	virtual void end_frame();

	virtual synfig::Color * start_scanline(int scanline);
	virtual bool end_scanline();
	virtual unsigned char* start_scanline_rgba(int scanline);
	virtual bool end_scanline_rgba();
};

/* === E N D =============================================================== */

#endif
