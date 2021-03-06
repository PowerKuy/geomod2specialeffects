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



/*! \file gmStaticProc_GM_Static3_.c
 *  gmStaticProc GM_Static3_ implementations
 *
 *  \date   2008-07-04
 */



#include <algorithm>


namespace GMlib {


  ///////////////////////////////////////
  // template <typename T, int n, int m>
  // class GM_Static3_<T, n, m>::

  /*! T	GM_Static3_<T, n, m>::dpr(T *a, T *b)
   *  \brief a*b innerproduct (row x column) (n x m)
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  T	GM_Static3_<T, n, m>::dpr(T *a, T *b)	{
    return (*a)*(*b)+ GM_Static3_<T,n-1,m>::dpr(a+1,b+m+1);
  }

  /*! void GM_Static3_<T, n, m>::eq1(T *a, T *b)
   *  \brief a = b  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::eq1(T *a, T *b) {
    (*a) = (*b);
    GM_Static3_<T,n-1,m>::eq1(a+1,b+m+1);
  }

  /*! void GM_Static3_<T, n, m>::eq2(T *a, T *b)
   *  \brief b = a  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::eq2(T *a, T *b) {
    (*b) = (*a);
    GM_Static3_<T,n-1,m>::eq2(a+1,b+m+1);
  }

  /*! void GM_Static3_<T, n, m>::eq3(T *a, T *b)
   *  \brief b = -a  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::eq3(T *a, T *b) {
    (*b) = -(*a);
    GM_Static3_<T,n-1,m>::eq3(a+1,b+m+1);
  }

  /*! void GM_Static3_<T, n, m>::sc(T *a, double b)
   *  \brief a *= b scale column vector
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::sc(T *a, double b)	{
    (*a) *= b;
    GM_Static2_<T,n-1,m>::sc(a+m+1,b);
  }

  /*! void GM_Static3_<T, n, m>::swp(T* a, T* b)
   *  \brief swap colomn a and line b
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::swp(T* a, T* b) {
    std::swap(*a,*b);
    GM_Static3_<T,n-1,m>::swp(a+m,b+1);
  }

  /*! void GM_Static3_<T, n, m>::trn(T* a, T* b)
   *  \brief // swap colomn a and line b
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::trn(T* a, T* b) {
    GM_Static3_<T,n,m>::swp(a,b);
    GM_Static3_<T,n-1,m>::trn(a+m+1,b+m+1);
  }

  /*! void GM_Static3_<T, n, m>::cm_x(T *a, T* b, T* c)
   *  \brief col = -mat x vec
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::cm_x(T *a, T* b, T* c)	{
    (*a) = -GM_Static_<T,m>::dpr(b,c);
    GM_Static3_<T,n-1,m>::cm_x(a+m+1,b+m+1,c);
  }

  /*! void GM_Static3_<T, n, m>::decomp(T *a, T* b)
   *  \brief Pending Documentation
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::decomp(T *a, T* b) {
    T c = GM_Static_<T,m>::dpr(a,b);
    GM_Static_<T,m>::decomp(a,b,c);
    GM_Static2_<T,n-1,m>::decomp1(a,b+m+1,c);
  }

  /*! void GM_Static3_<T, n, m>::decomp1(T *a, T* b, T& c)
   *  \brief Pending Documentation
   *
   *  Pending Documentation
   */
  template <typename T, int n, int m>
  inline
  void GM_Static3_<T, n, m>::decomp1(T *a, T* b, T& c) {
    c = GM_Static_<T,m>::dpr(a,b);
    GM_Static_<T,m>::decomp(a,b,c);
    GM_Static2_<T,n-1,m>::decomp1(a,b+m+1,c);
  }





  ///////////////////////////////////////
  // template <typename T, int m>
  // class GM_Static3_<T, 1, m>::


  /*! T	GM_Static3_<T, 1, m>::dpr(T *a, T *b)
   *  \brief a*b innerproduct (row x column) (n x m)
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  T	GM_Static3_<T, 1, m>::dpr(T *a, T *b)	{
    return (*a) * (*b);
  }


  /*! void GM_Static3_<T, 1, m>::eq1(T *a, T *b)
   *  \brief a = b  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::eq1(T *a, T *b) {
    (*a) = (*b);
  }


  /*! void GM_Static3_<T, 1, m>::eq2(T *a, T *b)
   *  \brief b = a  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::eq2(T *a, T *b) {
    (*b) = (*a);
  }


  /*! void GM_Static3_<T, 1, m>::eq3(T *a, T *b)
   *  \brief b = a  a-vector, b-diagonal in matrix
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::eq3(T *a, T *b) {
    (*b) = -(*a);
  }


  /*! void GM_Static3_<T, 1, m>::sc(T *a, double b)
   *  \brief a *= b scale column vector
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::sc(T *a, double b)	{
    (*a) *= b;
  }


  /*! void GM_Static3_<T, 1, m>::swp(T* a, T* b)
   *  \brief swap colomn a and line b
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::swp(T* a, T* b) {
    std::swap(*a,*b);
  }


  /*! void GM_Static3_<T, 1, m>::trn(T* a, T* b)
   *  \brief swap colomn a and line b
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::trn(T* a, T* b) {
    std::swap(*a,*b);
  }


  /*! void GM_Static3_<T, 1, m>::cm_x(T *a, T* b, T* c)
   *  \brief col = -mat x vec
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::cm_x(T *a, T* b, T* c)	{
    (*a) = -GM_Static_<T,m>::dpr(b,c);
  }


  /*! void GM_Static3_<T, 1, m>::decomp1(T *a, T* b, T& c)
   *  \brief Pending Documentation
   *
   *  Pending Documentation
   */
  template <typename T, int m>
  inline
  void GM_Static3_<T, 1, m>::decomp1(T *a, T* b, T& c) {
    c = GM_Static_<T,m>::dpr(a,b);
    GM_Static_<T,m>::decomp(a,b,c);
  }

}
