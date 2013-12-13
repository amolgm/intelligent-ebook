/*
 * step2.h
 *
 * Code generation for function 'step2'
 *
 * C source code generated on: Mon Mar 05 13:10:07 2012
 *
 */

#ifndef __STEP2_H__
#define __STEP2_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "step2_types.h"

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
extern void step2(const emxArray_uint8_T *norm_xaxis_filt, const emxArray_uint8_T *norm_yaxis_filt, uint8_T char_bin[900]);
extern void step2_initialize(void);
#endif
/* End of code generation (step2.h) */
