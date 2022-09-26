/*
 * lab2exe_E.cpp
 * Implementation file for complex number module
 *
 * ENSF 614 Lab 2 Exercise E
 */

#include "lab2exe_E.h"

cplx cplx_add(cplx z1, cplx z2)
{
  cplx result;

  result.real = z1.real + z2.real;
  result.imag = z1.imag + z2.imag;
  return result;
}
