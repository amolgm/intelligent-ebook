/*
 * step1.h
 *
 * Code generation for function 'step1'
 *
 * C source code generated on: Sun Mar 04 23:59:50 2012
 *
 */

#ifndef __STEP1_H__
#define __STEP1_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "step1_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern emxArray_uint8_T *emxCreateND_uint8_T(int32_T numDimensions, int32_T *size);
extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(uint8_T *data, int32_T numDimensions, int32_T *size);
extern emxArray_uint8_T *emxCreateWrapper_uint8_T(uint8_T *data, int32_T rows, int32_T cols);
extern emxArray_uint8_T *emxCreate_uint8_T(int32_T rows, int32_T cols);
extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);
extern void step1(emxArray_uint8_T *xaxis, emxArray_uint8_T *yaxis, emxArray_uint8_T *norm_xaxis_filt, emxArray_uint8_T *norm_yaxis_filt);
extern void step1_initialize(void);
#endif
/* End of code generation (step1.h) */
