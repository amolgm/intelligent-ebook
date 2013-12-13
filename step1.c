/*
 * step1.c
 *
 * Code generation for function 'step1'
 *
 * C source code generated on: Sun Mar 04 23:59:50 2012
 *
 */

/* Include files */
#include "step1.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

typedef struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray__common;

#endif

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

typedef struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_boolean_T;

#endif

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

typedef struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_int32_T;

#endif

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions);
static void b_emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T
  numDimensions);
static void c_emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T
  numDimensions);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static boolean_T eml_sort_le(const emxArray_uint8_T *v, const int32_T col[2],
  int32_T irow1, int32_T irow2);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T numDimensions);
static void unique(const emxArray_uint8_T *a, emxArray_uint8_T *b);

/* Function Definitions */
static void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

static void b_emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T
  numDimensions)
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
}

static void c_emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int32_T
  numDimensions)
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
}

/*
 *
 */
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  int32_T i;
  int32_T j;
  n = x->size[1];
  k = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  j = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = k;
  emxEnsureCapacity((emxArray__common *)y, j, (int32_T)sizeof(int32_T));
  j = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
  }
}

/*
 *
 */
static boolean_T eml_sort_le(const emxArray_uint8_T *v, const int32_T col[2],
  int32_T irow1, int32_T irow2)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  int32_T abscolk;
  boolean_T b0;
  p = TRUE;
  k = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (k < 2)) {
    if (col[k] < 0) {
      abscolk = col[k];
      if (abscolk <= MIN_int32_T) {
        abscolk = MAX_int32_T;
      } else {
        abscolk = -abscolk;
      }
    } else {
      abscolk = col[k];
    }

    abscolk = (abscolk - 1) * v->size[0] - 1;
    if (v->data[abscolk + irow1] == v->data[abscolk + irow2]) {
      b0 = TRUE;
    } else {
      b0 = FALSE;
    }

    if (!b0) {
      if (col[k] < 0) {
        if (v->data[abscolk + irow1] >= v->data[abscolk + irow2]) {
          p = TRUE;
        } else {
          p = FALSE;
        }
      } else if (v->data[abscolk + irow1] <= v->data[abscolk + irow2]) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      exitg1 = 1U;
    } else {
      k++;
    }
  }

  return p;
}

static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
{
  int32_T newNumel;
  int32_T loop_ub;
  int32_T i;
  void *newData;
  newNumel = 1;
  loop_ub = emxArray->numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    loop_ub = emxArray->allocatedSize;
    if (loop_ub < 16) {
      loop_ub = 16;
    }

    while (loop_ub < newNumel) {
      loop_ub <<= 1;
    }

    newData = calloc((uint32_T)loop_ub, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = loop_ub;
    emxArray->canFreeData = TRUE;
  }
}

static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

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

static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_boolean_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
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
}

/*
 *
 */
static void unique(const emxArray_uint8_T *a, emxArray_uint8_T *b)
{
  int32_T p;
  int32_T k0;
  int32_T col[2];
  int32_T k;
  emxArray_int32_T *idx;
  int32_T n;
  int32_T np1;
  emxArray_int32_T *idx0;
  int32_T i;
  int32_T m;
  int32_T j;
  int32_T nb;
  int32_T qEnd;
  int32_T kEnd;
  emxArray_uint8_T *ycol;
  int32_T exitg1;
  boolean_T b_p;
  boolean_T exitg2;
  emxArray_uint8_T *b_b;
  if (a->size[0] == 0) {
    p = b->size[0] * b->size[1];
    b->size[0] = a->size[0];
    b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b, p, (int32_T)sizeof(uint8_T));
    k0 = a->size[0] * a->size[1] - 1;
    for (p = 0; p <= k0; p++) {
      b->data[p] = a->data[p];
    }
  } else {
    for (k = 0; k < 2; k++) {
      col[k] = k + 1;
    }

    b_emxInit_int32_T(&idx, 1);
    n = a->size[0];
    p = idx->size[0];
    idx->size[0] = n;
    emxEnsureCapacity((emxArray__common *)idx, p, (int32_T)sizeof(int32_T));
    np1 = n + 1;
    for (k = 1; k <= n; k++) {
      idx->data[k - 1] = k;
    }

    for (k = 1; k <= n - 1; k += 2) {
      if (eml_sort_le(a, col, k, k + 1)) {
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    b_emxInit_int32_T(&idx0, 1);
    p = idx0->size[0];
    idx0->size[0] = n;
    emxEnsureCapacity((emxArray__common *)idx0, p, (int32_T)sizeof(int32_T));
    k0 = n - 1;
    for (p = 0; p <= k0; p++) {
      idx0->data[p] = 1;
    }

    i = 2;
    while (i < n) {
      m = i << 1;
      j = 1;
      for (k0 = 1 + i; k0 < np1; k0 = qEnd + i) {
        p = j;
        nb = k0;
        qEnd = j + m;
        if (qEnd > np1) {
          qEnd = np1;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if (eml_sort_le(a, col, idx->data[p - 1], idx->data[nb - 1])) {
            idx0->data[k] = idx->data[p - 1];
            p++;
            if (p == k0) {
              while (nb < qEnd) {
                k++;
                idx0->data[k] = idx->data[nb - 1];
                nb++;
              }
            }
          } else {
            idx0->data[k] = idx->data[nb - 1];
            nb++;
            if (nb == qEnd) {
              while (p < k0) {
                k++;
                idx0->data[k] = idx->data[p - 1];
                p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k + 1 <= kEnd; k++) {
          idx->data[(j + k) - 1] = idx0->data[k];
        }

        j = qEnd;
      }

      i = m;
    }

    emxFree_int32_T(&idx0);
    p = b->size[0] * b->size[1];
    b->size[0] = a->size[0];
    b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b, p, (int32_T)sizeof(uint8_T));
    k0 = a->size[0] * a->size[1] - 1;
    for (p = 0; p <= k0; p++) {
      b->data[p] = a->data[p];
    }

    b_emxInit_uint8_T(&ycol, 1);
    m = a->size[0];
    col[0] = m;
    col[1] = 1;
    p = ycol->size[0];
    ycol->size[0] = col[0];
    emxEnsureCapacity((emxArray__common *)ycol, p, (int32_T)sizeof(uint8_T));
    for (j = 0; j < 2; j++) {
      for (i = 0; i + 1 <= m; i++) {
        ycol->data[i] = b->data[(idx->data[i] + b->size[0] * j) - 1];
      }

      for (i = 0; i + 1 <= m; i++) {
        b->data[i + b->size[0] * j] = ycol->data[i];
      }
    }

    emxFree_uint8_T(&ycol);
    emxFree_int32_T(&idx);
    nb = 0;
    m = a->size[0];
    k = 0;
    while (k + 1 <= m) {
      k0 = k;
      do {
        exitg1 = 0U;
        k++;
        if (k + 1 > m) {
          exitg1 = 1U;
        } else {
          b_p = FALSE;
          j = 0;
          exitg2 = 0U;
          while ((exitg2 == 0U) && (j < 2)) {
            if (!(b->data[k0 + b->size[0] * j] == b->data[k + b->size[0] * j]))
            {
              b_p = TRUE;
              exitg2 = 1U;
            } else {
              j++;
            }
          }

          if (b_p) {
            exitg1 = 1U;
          }
        }
      } while (exitg1 == 0U);

      nb++;
      for (j = 0; j < 2; j++) {
        b->data[(nb + b->size[0] * j) - 1] = b->data[k0 + b->size[0] * j];
      }
    }

    if (1 > nb) {
      nb = 0;
    }

    emxInit_uint8_T(&b_b, 2);
    p = b_b->size[0] * b_b->size[1];
    b_b->size[0] = nb;
    b_b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b_b, p, (int32_T)sizeof(uint8_T));
    for (p = 0; p < 2; p++) {
      k0 = nb - 1;
      for (m = 0; m <= k0; m++) {
        b_b->data[m + b_b->size[0] * p] = b->data[m + b->size[0] * p];
      }
    }

    p = b->size[0] * b->size[1];
    b->size[0] = b_b->size[0];
    b->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b, p, (int32_T)sizeof(uint8_T));
    for (p = 0; p < 2; p++) {
      k0 = b_b->size[0] - 1;
      for (m = 0; m <= k0; m++) {
        b->data[m + b->size[0] * p] = b_b->data[m + b_b->size[0] * p];
      }
    }

    emxFree_uint8_T(&b_b);
  }
}

emxArray_uint8_T *emxCreateND_uint8_T(int32_T numDimensions, int32_T *size)
{
  emxArray_uint8_T *emx;
  int32_T numEl;
  int32_T loop_ub;
  int32_T i;
  c_emxInit_uint8_T(&emx, numDimensions);
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
  c_emxInit_uint8_T(&emx, numDimensions);
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
  c_emxInit_uint8_T(&emx, 2);
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
  c_emxInit_uint8_T(&emx, 2);
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

/*
 * function [norm_xaxis_filt norm_yaxis_filt] = step1(xaxis,yaxis)
 */
void step1(emxArray_uint8_T *xaxis, emxArray_uint8_T *yaxis, emxArray_uint8_T
           *norm_xaxis_filt, emxArray_uint8_T *norm_yaxis_filt)
{
  int32_T i0;
  emxArray_int32_T *r0;
  int32_T n;
  emxArray_uint8_T *r1;
  int32_T iv0[2];
  int32_T loop_ub;
  int32_T ix;
  emxArray_int32_T r2;
  emxArray_uint8_T *diff_y;
  uint32_T qY;
  uint8_T mtmp;
  emxArray_boolean_T *b_diff_y;
  emxArray_int32_T *r3;
  emxArray_uint8_T *b_yaxis;
  emxArray_boolean_T *c_diff_y;
  emxArray_uint8_T *b_xaxis;
  uint8_T b_mtmp;
  emxArray_uint8_T *c_xaxis;
  real_T x_normal;
  real_T y_normal;
  real_T d0;
  emxArray_uint8_T *norm_xy_filt;
  emxArray_uint8_T *r4;

  /* 'step1:2' assert(isa(xaxis,'uint8')); */
  /* 'step1:3' assert(isa(yaxis,'uint8')); */
  /* 'step1:5' diff_y = uint8(yaxis - [0 yaxis(1:end-1)]); */
  if (1 > yaxis->size[1] - 1) {
    i0 = -1;
  } else {
    i0 = yaxis->size[1] - 2;
  }

  b_emxInit_int32_T(&r0, 1);
  n = r0->size[0];
  r0->size[0] = i0 + 1;
  emxEnsureCapacity((emxArray__common *)r0, n, (int32_T)sizeof(int32_T));
  for (n = 0; n <= i0; n++) {
    r0->data[n] = 1 + n;
  }

  emxInit_uint8_T(&r1, 2);
  iv0[0] = 1;
  iv0[1] = r0->size[0];
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = 1 + iv0[1];
  emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(uint8_T));
  r1->data[0] = 0;
  loop_ub = iv0[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    ix = iv0[0] - 1;
    for (n = 0; n <= ix; n++) {
      r2 = *r0;
      r2.size = (int32_T *)&iv0;
      r2.numDimensions = 1;
      r1->data[n + r1->size[0] * (i0 + 1)] = yaxis->data[r2.data[n + r2.size[0] *
        i0] - 1];
    }
  }

  emxFree_int32_T(&r0);
  emxInit_uint8_T(&diff_y, 2);
  i0 = diff_y->size[0] * diff_y->size[1];
  diff_y->size[0] = 1;
  diff_y->size[1] = yaxis->size[1];
  emxEnsureCapacity((emxArray__common *)diff_y, i0, (int32_T)sizeof(uint8_T));
  loop_ub = yaxis->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    n = (int32_T)yaxis->data[yaxis->size[0] * i0];
    qY = (uint32_T)n - (uint32_T)r1->data[r1->size[0] * i0];
    if (qY > (uint32_T)n) {
      qY = 0U;
    }

    n = (int32_T)qY;
    diff_y->data[diff_y->size[0] * i0] = (uint8_T)n;
  }

  emxFree_uint8_T(&r1);

  /* 'step1:6' yaxis = yaxis(~(diff_y==max(diff_y))); */
  n = diff_y->size[1];
  mtmp = diff_y->data[0];
  if (n > 1) {
    for (ix = 1; ix + 1 <= n; ix++) {
      if (diff_y->data[ix] > mtmp) {
        mtmp = diff_y->data[ix];
      }
    }
  }

  emxInit_boolean_T(&b_diff_y, 2);
  i0 = b_diff_y->size[0] * b_diff_y->size[1];
  b_diff_y->size[0] = 1;
  b_diff_y->size[1] = diff_y->size[1];
  emxEnsureCapacity((emxArray__common *)b_diff_y, i0, (int32_T)sizeof(boolean_T));
  loop_ub = diff_y->size[0] * diff_y->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_diff_y->data[i0] = !(diff_y->data[i0] == mtmp);
  }

  emxInit_int32_T(&r3, 2);
  emxInit_uint8_T(&b_yaxis, 2);
  eml_li_find(b_diff_y, r3);
  i0 = b_yaxis->size[0] * b_yaxis->size[1];
  b_yaxis->size[0] = 1;
  b_yaxis->size[1] = r3->size[1];
  emxEnsureCapacity((emxArray__common *)b_yaxis, i0, (int32_T)sizeof(uint8_T));
  emxFree_boolean_T(&b_diff_y);
  loop_ub = r3->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_yaxis->data[b_yaxis->size[0] * i0] = yaxis->data[r3->data[r3->size[0] * i0]
      - 1];
  }

  i0 = yaxis->size[0] * yaxis->size[1];
  yaxis->size[0] = 1;
  yaxis->size[1] = b_yaxis->size[1];
  emxEnsureCapacity((emxArray__common *)yaxis, i0, (int32_T)sizeof(uint8_T));
  loop_ub = b_yaxis->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    yaxis->data[yaxis->size[0] * i0] = b_yaxis->data[b_yaxis->size[0] * i0];
  }

  emxFree_uint8_T(&b_yaxis);

  /* 'step1:7' xaxis = xaxis(~(diff_y==max(diff_y))); */
  n = diff_y->size[1];
  mtmp = diff_y->data[0];
  if (n > 1) {
    for (ix = 1; ix + 1 <= n; ix++) {
      if (diff_y->data[ix] > mtmp) {
        mtmp = diff_y->data[ix];
      }
    }
  }

  emxInit_boolean_T(&c_diff_y, 2);
  i0 = c_diff_y->size[0] * c_diff_y->size[1];
  c_diff_y->size[0] = 1;
  c_diff_y->size[1] = diff_y->size[1];
  emxEnsureCapacity((emxArray__common *)c_diff_y, i0, (int32_T)sizeof(boolean_T));
  loop_ub = diff_y->size[0] * diff_y->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    c_diff_y->data[i0] = !(diff_y->data[i0] == mtmp);
  }

  emxFree_uint8_T(&diff_y);
  emxInit_uint8_T(&b_xaxis, 2);
  eml_li_find(c_diff_y, r3);
  i0 = b_xaxis->size[0] * b_xaxis->size[1];
  b_xaxis->size[0] = 1;
  b_xaxis->size[1] = r3->size[1];
  emxEnsureCapacity((emxArray__common *)b_xaxis, i0, (int32_T)sizeof(uint8_T));
  emxFree_boolean_T(&c_diff_y);
  loop_ub = r3->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_xaxis->data[b_xaxis->size[0] * i0] = xaxis->data[r3->data[r3->size[0] * i0]
      - 1];
  }

  emxFree_int32_T(&r3);
  i0 = xaxis->size[0] * xaxis->size[1];
  xaxis->size[0] = 1;
  xaxis->size[1] = b_xaxis->size[1];
  emxEnsureCapacity((emxArray__common *)xaxis, i0, (int32_T)sizeof(uint8_T));
  loop_ub = b_xaxis->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    xaxis->data[xaxis->size[0] * i0] = b_xaxis->data[b_xaxis->size[0] * i0];
  }

  emxFree_uint8_T(&b_xaxis);

  /*  Char size normalization */
  /* 'step1:10' array_size = 29; */
  /* 'step1:11' w = double(max(xaxis)); */
  n = xaxis->size[1];
  mtmp = xaxis->data[0];
  if (n > 1) {
    for (ix = 1; ix + 1 <= n; ix++) {
      if (xaxis->data[ix] > mtmp) {
        mtmp = xaxis->data[ix];
      }
    }
  }

  /* 'step1:12' h = double(max(yaxis)); */
  n = yaxis->size[1];
  b_mtmp = yaxis->data[0];
  if (n > 1) {
    for (ix = 1; ix + 1 <= n; ix++) {
      if (yaxis->data[ix] > b_mtmp) {
        b_mtmp = yaxis->data[ix];
      }
    }
  }

  emxInit_uint8_T(&c_xaxis, 2);

  /* 'step1:13' x_normal = array_size/w; */
  x_normal = 29.0 / (real_T)mtmp;

  /* 'step1:14' y_normal = array_size/h; */
  y_normal = 29.0 / (real_T)b_mtmp;

  /* 'step1:15' norm_xaxis = xaxis * x_normal; */
  /* 'step1:16' norm_yaxis = yaxis * y_normal; */
  /*  Removing duplicate coordinates */
  /* 'step1:19' norm_xy = [norm_xaxis; norm_yaxis]; */
  /* 'step1:20' norm_xy_filt = uint8(unique(norm_xy','rows','first')'); */
  i0 = c_xaxis->size[0] * c_xaxis->size[1];
  c_xaxis->size[0] = xaxis->size[1];
  c_xaxis->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)c_xaxis, i0, (int32_T)sizeof(uint8_T));
  loop_ub = xaxis->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    d0 = (real_T)xaxis->data[xaxis->size[0] * i0] * x_normal;
    d0 = d0 < 0.0 ? ceil(d0 - 0.5) : floor(d0 + 0.5);
    if (d0 < 256.0) {
      if (d0 >= 0.0) {
        mtmp = (uint8_T)d0;
      } else {
        mtmp = 0;
      }
    } else {
      mtmp = MAX_uint8_T;
    }

    c_xaxis->data[i0] = mtmp;
  }

  loop_ub = yaxis->size[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    d0 = (real_T)yaxis->data[yaxis->size[0] * i0] * y_normal;
    d0 = d0 < 0.0 ? ceil(d0 - 0.5) : floor(d0 + 0.5);
    if (d0 < 256.0) {
      if (d0 >= 0.0) {
        mtmp = (uint8_T)d0;
      } else {
        mtmp = 0;
      }
    } else {
      mtmp = MAX_uint8_T;
    }

    c_xaxis->data[i0 + c_xaxis->size[0]] = mtmp;
  }

  emxInit_uint8_T(&norm_xy_filt, 2);
  emxInit_uint8_T(&r4, 2);
  unique(c_xaxis, r4);
  i0 = norm_xy_filt->size[0] * norm_xy_filt->size[1];
  norm_xy_filt->size[0] = 2;
  norm_xy_filt->size[1] = r4->size[0];
  emxEnsureCapacity((emxArray__common *)norm_xy_filt, i0, (int32_T)sizeof
                    (uint8_T));
  emxFree_uint8_T(&c_xaxis);
  loop_ub = r4->size[0] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    for (n = 0; n < 2; n++) {
      norm_xy_filt->data[n + norm_xy_filt->size[0] * i0] = r4->data[i0 +
        r4->size[0] * n];
    }
  }

  emxFree_uint8_T(&r4);

  /* 'step1:21' norm_xaxis_filt = norm_xy_filt(1,:); */
  i0 = norm_xy_filt->size[1];
  n = norm_xaxis_filt->size[0] * norm_xaxis_filt->size[1];
  norm_xaxis_filt->size[0] = 1;
  norm_xaxis_filt->size[1] = i0;
  emxEnsureCapacity((emxArray__common *)norm_xaxis_filt, n, (int32_T)sizeof
                    (uint8_T));
  loop_ub = i0 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    norm_xaxis_filt->data[norm_xaxis_filt->size[0] * i0] = norm_xy_filt->
      data[norm_xy_filt->size[0] * i0];
  }

  /* 'step1:22' norm_yaxis_filt = norm_xy_filt(2,:); */
  i0 = norm_xy_filt->size[1];
  n = norm_yaxis_filt->size[0] * norm_yaxis_filt->size[1];
  norm_yaxis_filt->size[0] = 1;
  norm_yaxis_filt->size[1] = i0;
  emxEnsureCapacity((emxArray__common *)norm_yaxis_filt, n, (int32_T)sizeof
                    (uint8_T));
  loop_ub = i0 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    norm_yaxis_filt->data[norm_yaxis_filt->size[0] * i0] = norm_xy_filt->data[1
      + norm_xy_filt->size[0] * i0];
  }

  emxFree_uint8_T(&norm_xy_filt);
}

void step1_initialize(void)
{
}

/* End of code generation (step1.c) */
