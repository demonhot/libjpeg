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
** This class represents the refinement specification box, carrying the
** number of refinement scans in the base and residual layer of the
** image.
**
** $Id: refinementspecbox.cpp,v 1.3 2014/09/30 08:33:15 thor Exp $
**
*/

/// Includes
#include "boxes/box.hpp"
#include "boxes/refinementspecbox.hpp"
#include "io/bytestream.hpp"
#include "io/memorystream.hpp"
///

/// RefinementSpecBox::ParseBoxContent
bool RefinementSpecBox::ParseBoxContent(class ByteStream *stream,UQUAD boxsize)
{
  LONG v;
  
  if (boxsize != 1)
    JPG_THROW(MALFORMED_STREAM,"RefinementSpecBox::ParseBoxContent",
              "Malformed JPEG stream - the size of the refinement spec box is incorrect");

  
  v = stream->Get();

  if ((v >> 4) > 4)
    JPG_THROW(MALFORMED_STREAM,"RefinementSpecBox::ParseBoxContent",
              "Malformed JPEG stream - the number of refinement scans must be smaller or equal than four");

  m_ucBaseRefinementScans = v >> 4;

  if ((v & 0x0f) > 4)
    JPG_THROW(MALFORMED_STREAM,"RefinementSpecBox::ParseBoxContent",
              "Malformed JPEG stream - the number of residual refinement scans must be smaller or equal than four");

  m_ucResidualRefinementScans = v & 0x0f;

  return true;
}
///

/// RefinementSpecBox::CreateBoxContent
// Create the contents of the refinement spec box.
bool RefinementSpecBox::CreateBoxContent(class MemoryStream *target)
{
  target->Put((m_ucBaseRefinementScans << 4) | m_ucResidualRefinementScans);

  return true;
}
///
