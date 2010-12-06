/**********************************************************************************
**
** Copyright (C) 1994 Narvik University College
** Contact: GMlib Online Portal at http://episteme.hin.no
**
** This file is part of the Geometric Modeling Library, GMlib.
**
** GMlib is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** GMlib is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with GMlib.  If not, see <http://www.gnu.org/licenses/>.
**
**********************************************************************************/



/*! \file gmPathTrack.h
 *
 *  Interface for the PathTrack class.
 *
 *  \date 2009-09-03
 */

#ifndef __gmPATHTRACK_H__
#define __gmPATHTRACK_H__


// Local GMlib includes
#include "gmDisplayObject.h"


namespace GMlib {


  /*! \class  PathTrack gmPathTrack.h <gmPathTrack>
   *  \brief
   *
   * When this object is attached to another *DisplayObject, it will keep track of
   * the path of the object. By setting the element size and the stride between
   * points one can control the behaviour of the PathTrack object.
   */
  class PathTrack : public DisplayObject {
  public:
    PathTrack( int max_elements = 50, int elementstride = 1, const Color& c = Color( 155, 100, 0 ) );

  protected:
    void                      localDisplay();
    void                      localSimulate( double dt );
    void                      setColor( const Color& c );

  private:
    Array< Point<float,3> >   _recent_path;
    int							          _element;
    int							          _element_stride;
    int							          _stride_current_element;
    bool						          _path_full;
    Color					            _color;

  }; // END class

} // END namespace

#endif // __gmPATHTRACK_H__

