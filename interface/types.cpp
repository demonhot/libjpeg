/*************************************************************************

    This project implements a complete(!) JPEG (10918-1 ITU.T-81) codec,
    plus a library that can be used to encode and decode JPEG streams. 
    It also implements ISO/IEC 18477 aka JPEG XT which is an extension
    towards intermediate, high-dynamic-range lossy and lossless coding
    of JPEG. In specific, it supports ISO/IEC 18477-3/-6/-7/-8 encoding.

    Copyright (C) 2012-2017 Thomas Richter, University of Stuttgart and
    Accusoft.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/
/*
 * Type definition: Some system independent type definitions
 * (thor's pecularities)
 * $Id: types.cpp,v 1.7 2014/09/30 08:33:17 thor Exp $
 *
 * The following header defines basic types to be used in the J2K interface
 * routines. Especially, this file must be adapted if your compiler has
 * different ideas what a "unsigned long" is as we *MUST* fix the width
 * of elementary data types. Especially, do not use types not defined here for
 * interface glue routines.
 *
 * This is the "internal" header file defining internal types, importing the
 * types from the external "jpgtypes" header.
 */

