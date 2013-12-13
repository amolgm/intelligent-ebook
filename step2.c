/*
 * step2.c
 *
 * Code generation for function 'step2'
 *
 * C source code generated on: Mon Mar 05 13:10:07 2012
 *
 */

/* Include files */
#include "step2.h"
#include "lcd.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */	/*
static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T numDimensions);  */

/* Function Definitions */	/*
static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T numDimensions)
{
  emxArray_uint8_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
} */
/*
emxArray_uint8_T *emxCreateND_uint8_T(int32_T numDimensions, int32_T *size)
{
  emxArray_uint8_T *emx;
  int32_T numEl;
  int32_T loop_ub;
  int32_T i;
  emxInit_uint8_T(&emx, numDimensions);
  numEl = 1;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (uint8_T *)calloc((uint32_T)numEl, sizeof(uint8_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_uint8_T *emxCreateWrapperND_uint8_T(uint8_T *data, int32_T
  numDimensions, int32_T *size)
{
  emxArray_uint8_T *emx;
  int32_T numEl;
  int32_T loop_ub;
  int32_T i;
  emxInit_uint8_T(&emx, numDimensions);
  numEl = 1;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = FALSE;
  return emx;
}

emxArray_uint8_T *emxCreateWrapper_uint8_T(uint8_T *data, int32_T rows, int32_T
  cols)
{
  emxArray_uint8_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_uint8_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = FALSE;
  return emx;
}

emxArray_uint8_T *emxCreate_uint8_T(int32_T rows, int32_T cols)
{
  emxArray_uint8_T *emx;
  int32_T size[2];
  int32_T numEl;
  int32_T i;
  size[0] = rows;
  size[1] = cols;
  emxInit_uint8_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (uint8_T *)calloc((uint32_T)numEl, sizeof(uint8_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray)
{
  emxFree_uint8_T(&emxArray);
}
*/
/*
 * function char_bin = step2(norm_xaxis_filt,norm_yaxis_filt)
 */
void step2(const emxArray_uint8_T *norm_xaxis_filt, const emxArray_uint8_T
           *norm_yaxis_filt, uint8_T char_bin[900])
{
  int32_T i;
  int32_T j;
  int32_T i0;
  uint8_T xtmp;

  /* 'step2:2' assert(isa(norm_xaxis_filt,'uint8')); */
  /* 'step2:3' assert(isa(norm_yaxis_filt,'uint8')); */
  /* 'step2:5' array_size = 29; */
  /*  Binarization */
  /* 'step2:7' char_bin = zeros(array_size+1,array_size+1,'uint8'); */
  memset((void *)&char_bin[0], 0, 900U * sizeof(uint8_T));

  /* 'step2:8' len = length(norm_xaxis_filt); */
  /* 'step2:9' for i=1:len */
  for (i = 0; i <= norm_xaxis_filt->size[1] - 1; i++) {
    /* 'step2:10' char_bin(norm_yaxis_filt(i)+1,norm_xaxis_filt(i)+1) = 1; */
    j = (int32_T)((uint32_T)norm_yaxis_filt->data[i] + 1U);
    if ((uint32_T)j > 255U) {
      j = 255;
    }

    i0 = (int32_T)((uint32_T)norm_xaxis_filt->data[i] + 1U);
    if ((uint32_T)i0 > 255U) {
      i0 = 255;
    }

    char_bin[(j + 30 * (i0 - 1)) - 1] = 1;
  }

  /* 'step2:12' char_bin = flipud(char_bin); */
  for (j = 0; j < 30; j++) {
    for (i = 0; i < 15; i++) {
      xtmp = char_bin[i + 30 * j];
      char_bin[i + 30 * j] = char_bin[(30 * j - i) + 29];
      char_bin[(30 * j - i) + 29] = xtmp;
    }
  }
}

void step2_initialize(void)
{
}

/* End of code generation (step2.c) */
