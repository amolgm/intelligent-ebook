/*
 * step3.c
 *
 * Code generation for function 'step3'
 *
 * C source code generated on: Mon Mar 05 17:51:56 2012
 *
 */

/* Include files */
#include "step3.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_sum(const uint8_T x[180], real_T y[6]);
static void sum(const uint8_T x[180], real_T y[30]);

/* Function Definitions */

/*
 *
 */
static void b_sum(const uint8_T x[180], real_T y[6])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  ix = -1;
  iy = -1;
  for (i = 0; i < 6; i++) {
    ixstart = ix + 1;
    ix++;
    s = (real_T)x[ixstart];
    for (ixstart = 0; ixstart < 29; ixstart++) {
      ix++;
      s += (real_T)x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/*
 *
 */
static void sum(const uint8_T x[180], real_T y[30])
{
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  ix = -1;
  iy = -1;
  for (i = 0; i < 30; i++) {
    ixstart = ix + 1;
    ix++;
    s = (real_T)x[ixstart];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ix++;
      s += (real_T)x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/*
 * function char_vec = step3(char_bin)
 */
void step3(uint8_T char_bin[900], uint8_T char_vec[10])
{
  int32_T i;
  int32_T j;
  uint8_T b_char_bin[180];
  real_T x[30];
  real_T y;
  real_T b_y;
  real_T c_y;
  real_T d_y;
  real_T e_y;
  real_T b_x[6];
  real_T f_y;
  real_T g_y;
  real_T h_y;
  real_T i_y;
  real_T j_y;
  uint8_T u0;

  /* 'step3:2' assert(isa(char_bin,'uint8')); */
  /*  Noise removal */
  /*  For edge elements */
  /* 'step3:7' pic_dim = 30; */
  /* (array_size+1) */
  /*  Bottom edge (last row) */
  /* 'step3:10' for i=1:pic_dim */
  for (i = 0; i < 30; i++) {
    /* 'step3:11' if char_bin(pic_dim,i)==1 */
    if (char_bin[29 + 30 * i] == 1) {
      /* 'step3:12' if i == 1 && char_bin(pic_dim-1,1)==0 && char_bin(pic_dim,2)==0 */
      if ((1 + i == 1) && (char_bin[28] == 0) && (char_bin[59] == 0)) {
        /* 'step3:13' char_bin(pic_dim,1) = 0; */
        char_bin[29] = 0;
      } else if ((1 + i == 30) && (char_bin[898] == 0) && (char_bin[869] == 0))
      {
        /* 'step3:14' elseif i == pic_dim && char_bin(pic_dim-1,pic_dim)==0 && ... */
        /* 'step3:15'                 char_bin(pic_dim,pic_dim-1) == 0 */
        /* 'step3:16' char_bin(pic_dim,pic_dim) = 0; */
        char_bin[899] = 0;
      } else {
        if ((1 + i != 1) && (1 + i != 30) && (char_bin[29 + 30 * (i - 1)] == 0) &&
            (char_bin[29 + 30 * (i + 1)] == 0) && (char_bin[28 + 30 * i] == 0))
        {
          /* 'step3:17' elseif i~=1 && i~=pic_dim */
          /* 'step3:18' if char_bin(pic_dim,i-1)==0 && char_bin(pic_dim,i+1)==0 && ... */
          /* 'step3:19'                 char_bin(pic_dim-1,i)==0 */
          /* 'step3:20' char_bin(pic_dim,i) = 0; */
          char_bin[29 + 30 * i] = 0;
        }
      }
    }
  }

  /*  Top edge (first row) */
  /* 'step3:27' for i=1:pic_dim */
  for (i = 0; i < 30; i++) {
    /* 'step3:28' if char_bin(1,i)==1 */
    if (char_bin[30 * i] == 1) {
      /* 'step3:29' if i == 1 && char_bin(2,1)==0 && char_bin(1,2)==0 */
      if ((1 + i == 1) && (char_bin[1] == 0) && (char_bin[30] == 0)) {
        /* 'step3:30' char_bin(1,1) = 0; */
        char_bin[0] = 0;
      } else if ((1 + i == 30) && (char_bin[840] == 0) && (char_bin[871] == 0))
      {
        /* 'step3:31' elseif i == pic_dim && char_bin(1,pic_dim-1)==0 && ... */
        /* 'step3:32'                 char_bin(2,pic_dim) == 0 */
        /* 'step3:33' char_bin(1,pic_dim) = 0; */
        char_bin[870] = 0;
      } else {
        if ((1 + i != 1) && (1 + i != 30) && (char_bin[30 * (i - 1)] == 0) &&
            (char_bin[30 * (i + 1)] == 0) && (char_bin[1 + 30 * i] == 0)) {
          /* 'step3:34' elseif i~=1 && i~=pic_dim */
          /* 'step3:35' if char_bin(1,i-1)==0 && char_bin(1,i+1)==0 && ... */
          /* 'step3:36'                 char_bin(2,i)==0 */
          /* 'step3:37' char_bin(1,i) = 0; */
          char_bin[30 * i] = 0;
        }
      }
    }
  }

  /*  Left edge (first column) */
  /* 'step3:44' for i=2:pic_dim-1 */
  for (i = 0; i < 28; i++) {
    /* 'step3:45' if char_bin(i,1)==1 */
    if ((char_bin[1 + i] == 1) && (char_bin[i] == 0) && (char_bin[2 + i] == 0) &&
        (char_bin[i + 31] == 0)) {
      /* 'step3:46' if char_bin(i-1,1)==0 && char_bin(i+1,1)==0 && ... */
      /* 'step3:47'                 char_bin(i,2)==0 */
      /* 'step3:48' char_bin(i,1) = 0; */
      char_bin[1 + i] = 0;
    }
  }

  /*  Right edge (last column) */
  /* 'step3:54' for i=2:pic_dim-1 */
  for (i = 0; i < 28; i++) {
    /* 'step3:55' if char_bin(i,pic_dim)==1 */
    if ((char_bin[i + 871] == 1) && (char_bin[870 + i] == 0) && (char_bin[i +
         872] == 0) && (char_bin[i + 841] == 0)) {
      /* 'step3:56' if char_bin(i-1,pic_dim)==0 && char_bin(i+1,pic_dim)==0 && ... */
      /* 'step3:57'                 char_bin(i,pic_dim-1)==0 */
      /* 'step3:58' char_bin(i,pic_dim) = 0; */
      char_bin[i + 871] = 0;
    }
  }

  /*  for between the image */
  /* 'step3:64' for i=2:size(char_bin,1)-1 */
  for (i = 0; i < 28; i++) {
    /* 'step3:65' for j=2:size(char_bin,1)-1 */
    for (j = 0; j < 28; j++) {
      /* 'step3:66' if char_bin(i,j) == 1 */
      if ((char_bin[(i + 30 * (1 + j)) + 1] == 1) && (char_bin[(i + 30 * (2 + j))
           + 1] == 0) && (char_bin[(i + 30 * j) + 1] == 0) && (char_bin[(i + 30 *
            (1 + j)) + 2] == 0) && (char_bin[i + 30 * (1 + j)] == 0)) {
        /* 'step3:67' if char_bin(i,j+1)==0 && char_bin(i,j-1)==0 && ... */
        /* 'step3:68'                       char_bin(i+1,j)==0 && char_bin(i-1,j)==0 */
        /* 'step3:69' char_bin(i,j)=0; */
        char_bin[(i + 30 * (1 + j)) + 1] = 0;
      }
    }
  }

  /* 'step3:75' char_hz = uint8([sum(sum(char_bin(1:6,:))); sum(sum((char_bin(7:12,:)))); ... */
  /* 'step3:76'     sum(sum(char_bin(13:18,:))); sum(sum(char_bin(19:24,:))); ... */
  /* 'step3:77'     sum(sum(char_bin(25:30,:)))]); */
  for (i = 0; i < 30; i++) {
    for (j = 0; j < 6; j++) {
      b_char_bin[j + 6 * i] = char_bin[j + 30 * i];
    }
  }

  sum(b_char_bin, x);
  y = x[0];
  for (i = 0; i < 29; i++) {
    y += x[i + 1];
  }

  for (i = 0; i < 30; i++) {
    for (j = 0; j < 6; j++) {
      b_char_bin[j + 6 * i] = char_bin[(j + 30 * i) + 6];
    }
  }

  sum(b_char_bin, x);
  b_y = x[0];
  for (i = 0; i < 29; i++) {
    b_y += x[i + 1];
  }

  for (i = 0; i < 30; i++) {
    for (j = 0; j < 6; j++) {
      b_char_bin[j + 6 * i] = char_bin[(j + 30 * i) + 12];
    }
  }

  sum(b_char_bin, x);
  c_y = x[0];
  for (i = 0; i < 29; i++) {
    c_y += x[i + 1];
  }

  for (i = 0; i < 30; i++) {
    for (j = 0; j < 6; j++) {
      b_char_bin[j + 6 * i] = char_bin[(j + 30 * i) + 18];
    }
  }

  sum(b_char_bin, x);
  d_y = x[0];
  for (i = 0; i < 29; i++) {
    d_y += x[i + 1];
  }

  for (i = 0; i < 30; i++) {
    for (j = 0; j < 6; j++) {
      b_char_bin[j + 6 * i] = char_bin[(j + 30 * i) + 24];
    }
  }

  sum(b_char_bin, x);
  e_y = x[0];
  for (i = 0; i < 29; i++) {
    e_y += x[i + 1];
  }

  /* 'step3:78' char_vt = uint8([sum(sum(char_bin(:,1:6))); sum(sum(char_bin(:,7:12))); ... */
  /* 'step3:79'     sum(sum(char_bin(:,13:18))); sum(sum(char_bin(:,19:24))); ... */
  /* 'step3:80'     sum(sum(char_bin(:,25:30)))]); */
  b_sum(*(uint8_T (*)[180])&char_bin[0], b_x);
  f_y = b_x[0];
  for (i = 0; i < 5; i++) {
    f_y += b_x[i + 1];
  }

  b_sum(*(uint8_T (*)[180])&char_bin[180], b_x);
  g_y = b_x[0];
  for (i = 0; i < 5; i++) {
    g_y += b_x[i + 1];
  }

  b_sum(*(uint8_T (*)[180])&char_bin[360], b_x);
  h_y = b_x[0];
  for (i = 0; i < 5; i++) {
    h_y += b_x[i + 1];
  }

  b_sum(*(uint8_T (*)[180])&char_bin[540], b_x);
  i_y = b_x[0];
  for (i = 0; i < 5; i++) {
    i_y += b_x[i + 1];
  }

  b_sum(*(uint8_T (*)[180])&char_bin[720], b_x);
  j_y = b_x[0];
  for (i = 0; i < 5; i++) {
    j_y += b_x[i + 1];
  }

  /* 'step3:82' char_vec = uint8([char_hz; char_vt]); */
  y = y < 0.0 ? ceil(y - 0.5) : floor(y + 0.5);
  if (y < 256.0) {
    if (y >= 0.0) {
      u0 = (uint8_T)y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[0] = u0;
  b_y = b_y < 0.0 ? ceil(b_y - 0.5) : floor(b_y + 0.5);
  if (b_y < 256.0) {
    if (b_y >= 0.0) {
      u0 = (uint8_T)b_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[1] = u0;
  c_y = c_y < 0.0 ? ceil(c_y - 0.5) : floor(c_y + 0.5);
  if (c_y < 256.0) {
    if (c_y >= 0.0) {
      u0 = (uint8_T)c_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[2] = u0;
  d_y = d_y < 0.0 ? ceil(d_y - 0.5) : floor(d_y + 0.5);
  if (d_y < 256.0) {
    if (d_y >= 0.0) {
      u0 = (uint8_T)d_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[3] = u0;
  e_y = e_y < 0.0 ? ceil(e_y - 0.5) : floor(e_y + 0.5);
  if (e_y < 256.0) {
    if (e_y >= 0.0) {
      u0 = (uint8_T)e_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[4] = u0;
  f_y = f_y < 0.0 ? ceil(f_y - 0.5) : floor(f_y + 0.5);
  if (f_y < 256.0) {
    if (f_y >= 0.0) {
      u0 = (uint8_T)f_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[5] = u0;
  g_y = g_y < 0.0 ? ceil(g_y - 0.5) : floor(g_y + 0.5);
  if (g_y < 256.0) {
    if (g_y >= 0.0) {
      u0 = (uint8_T)g_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[6] = u0;
  h_y = h_y < 0.0 ? ceil(h_y - 0.5) : floor(h_y + 0.5);
  if (h_y < 256.0) {
    if (h_y >= 0.0) {
      u0 = (uint8_T)h_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[7] = u0;
  i_y = i_y < 0.0 ? ceil(i_y - 0.5) : floor(i_y + 0.5);
  if (i_y < 256.0) {
    if (i_y >= 0.0) {
      u0 = (uint8_T)i_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[8] = u0;
  j_y = j_y < 0.0 ? ceil(j_y - 0.5) : floor(j_y + 0.5);
  if (j_y < 256.0) {
    if (j_y >= 0.0) {
      u0 = (uint8_T)j_y;
    } else {
      u0 = 0;
    }
  } else {
    u0 = MAX_uint8_T;
  }

  char_vec[9] = u0;
}

void step3_initialize(void)
{
}

/* End of code generation (step3.c) */
