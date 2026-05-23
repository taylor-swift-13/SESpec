#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (mat_sum : Z -> Z -> Z -> Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (ksi_elem : Z -> Z -> Z) */
/*@ Extern Coq (qb6_elem : Z -> Z -> Z -> Z) */
/*@ Extern Coq (dq_elem : Z -> Z -> Z -> Z -> Z) */

int triple_fabs_max(int a, int b, int c)
/*@

Require emp
Ensure (-c > -a && -b <= -a && c < 0 && b < 0 && a < 0 && __return == -c) || (-c > a && -b <= a && c < 0 && b < 0 && a >= 0 && __return == -c) || (-c > a && b <= a && c < 0 && b >= 0 && a >= 0 && __return == -c) || (-c > -a && b <= -a && c < 0 && b >= 0 && a < 0 && __return == -c) || (c > -a && b <= -a && c >= 0 && b >= 0 && a < 0 && __return == c) || (c > a && b <= a && c >= 0 && b >= 0 && a >= 0 && __return == c) || (c > a && -b <= a && c >= 0 && b < 0 && a >= 0 && __return == c) || (c > -a && -b <= -a && c >= 0 && b < 0 && a < 0 && __return == c) || (c > -b && -b > -a && c >= 0 && b < 0 && a < 0 && __return == c) || (c > -b && -b > a && c >= 0 && b < 0 && a >= 0 && __return == c) || (c > b && b > a && c >= 0 && b >= 0 && a >= 0 && __return == c) || (c > b && b > -a && c >= 0 && b >= 0 && a < 0 && __return == c) || (-c > b && b > -a && c < 0 && b >= 0 && a < 0 && __return == -c) || (-c > b && b > a && c < 0 && b >= 0 && a >= 0 && __return == -c) || (-c > -b && -b > a && c < 0 && b < 0 && a >= 0 && __return == -c) || (-c > -b && -b > -a && c < 0 && b < 0 && a < 0 && __return == -c) || (-c <= -b && -b > -a && c < 0 && b < 0 && a < 0 && __return == -b) || (-c <= -b && -b > a && c < 0 && b < 0 && a >= 0 && __return == -b) || (-c <= b && b > a && c < 0 && b >= 0 && a >= 0 && __return == b) || (-c <= b && b > -a && c < 0 && b >= 0 && a < 0 && __return == b) || (c <= b && b > -a && c >= 0 && b >= 0 && a < 0 && __return == b) || (c <= b && b > a && c >= 0 && b >= 0 && a >= 0 && __return == b) || (c <= -b && -b > a && c >= 0 && b < 0 && a >= 0 && __return == -b) || (c <= -b && -b > -a && c >= 0 && b < 0 && a < 0 && __return == -b) || (c <= -a && -b <= -a && c >= 0 && b < 0 && a < 0 && __return == -a) || (c <= a && -b <= a && c >= 0 && b < 0 && a >= 0 && __return == a) || (c <= a && b <= a && c >= 0 && b >= 0 && a >= 0 && __return == a) || (c <= -a && b <= -a && c >= 0 && b >= 0 && a < 0 && __return == -a) || (-c <= -a && b <= -a && c < 0 && b >= 0 && a < 0 && __return == -a) || (-c <= a && b <= a && c < 0 && b >= 0 && a >= 0 && __return == a) || (-c <= a && -b <= a && c < 0 && b < 0 && a >= 0 && __return == a) || (-c <= -a && -b <= -a && c < 0 && b < 0 && a < 0 && __return == -a)
*/
{
    int fa = a; if (fa < 0) fa = -fa;
    int fb = b; if (fb < 0) fb = -fb;
    int fc = c; if (fc < 0) fc = -fc;
    int m = fa;
    if (fb > m) m = fb;
    if (fc > m) m = fc;
    return m;
}

void vec_cross3(int *out, int *a, int *b)
/*@
With out_l a_l b_l
Require store_int_ptr(out) && store_int_ptr(a) && store_int_ptr(b)
Ensure emp
*/
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
    return;
}

void vec_add(int *out, int *A, int *B, int n)
/*@
With out_l A_l B_l
Require store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100 && store_int_array(B, n, B_l) && n > 0 && n < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= i && i <= n) &&
    (n == n@pre)
    */
for (int i = 0; i < n; i++) {
        out[i] = A[i] + B[i];
    }
    return;
}

void vec_scale(int *out, int *A, int k, int n)
/*@
With out_l A_l
Require store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= i && i <= n) &&
    (n == n@pre) &&
    (k == k@pre) &&
    (true)) &&
    (true)) &&
    (forall (j:Z), i <= j && j < n => out[j] == out[j]@pre)
    */
for (int i = 0; i < n; i++) {
        out[i] = A[i] * k;
    }
    return;
}

void vec_sub(int *out, int *A, int *B, int n)
/*@
With out_l A_l B_l
Require store_int_array(out, n, out_l) && n > 0 && n < 100 && store_int_array(A, n, A_l) && n > 0 && n < 100 && store_int_array(B, n, B_l) && n > 0 && n < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= i && i <= n) &&
    (forall (k:Z), i <= k && k < n => out[k] == out[k]@pre)
    */
for (int i = 0; i < n; i++) {
        out[i] = A[i] - B[i];
    }
    return;
}

void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
/*@
With out_l A_l B_l
Require store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (i == 0 || (0 <= i && i <= ra)) &&
    (cb == cb@pre) &&
    (ca_rb == ca_rb@pre) &&
    (ra == ra@pre) &&
    (B == B@pre) &&
    (A == A@pre) &&
    (out == out@pre)
    */
for (int i = 0; i < ra; i++) {
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= j <= cb;
          loop invariant \true;
          loop assigns j, out[i * cb .. i * cb + cb - 1];
        */
        /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= j && j <= cb)
    */
for (int j = 0; j < cb; j++) {
            int s = 0;
            
            /* >>> LOOP INVARIANT TO FILL <<< */
            
            /*@
              loop invariant 0 <= k <= ca_rb;
              loop invariant s == mat_sum(A, B, ca_rb, cb, i, j, k);
              loop invariant \true;
              loop assigns k, s;
            */
            /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= k && k <= ca_rb) &&
    (s == mat_sum(A, B, ca_rb, cb, i, j, k))
    */
for (int k = 0; k < ca_rb; k++) {
                s = s + A[i * ca_rb + k] * B[k * cb + j];
            }
            
            out[i * cb + j] = s;
        }
    }
    return;
}

void q_to_C(int *C, int *q)
/*@
With C_l q_l
Require store_int_ptr(C) && store_int_ptr(q)
Ensure emp
*/
{
    int x = q[0];
    int y = q[1];
    int z = q[2];
    int w = q[3];

    C[0] = 1 - 2 * (y * y + z * z);
    C[1] = 2 * (x * y - z * w);
    C[2] = 2 * (x * z + y * w);

    C[3] = 2 * (x * y + z * w);
    C[4] = 1 - 2 * (x * x + z * z);
    C[5] = 2 * (y * z - x * w);

    C[6] = 2 * (x * z - y * w);
    C[7] = 2 * (y * z + x * w);
    C[8] = 1 - 2 * (x * x + y * y);
    return;
}


int limit_abs(int x, int lim)
/*@

Require emp
Ensure (x >= -lim && x <= lim && __return == x) || (x < -lim && x <= lim && __return == -lim) || (x > lim && __return == lim)
*/
{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}

void q_to_Ksi(int *Ksi, int *q)
/*@
With Ksi_l q_l
Require store_int_ptr(Ksi) && store_int_ptr(q)
Ensure emp
*/
{
    int x = q[0];
    int y = q[1];
    int z = q[2];
    int w = q[3];

    Ksi[0] =  w;  Ksi[1]  = -z;  Ksi[2]  =  y;
    Ksi[3] =  z;  Ksi[4]  =  w;  Ksi[5]  = -x;
    Ksi[6] = -y;  Ksi[7]  =  x;  Ksi[8]  =  w;
    Ksi[9] = -x;  Ksi[10] = -y;  Ksi[11] = -z;
    return;
}

void q_normalize(int *q)
/*@
With q_v
Require *(q) == q_v
Ensure (*q == q_v)
*/
{
    (void)q;
    return;
}

void StsModify(int *pdeltaZ, int *q,
               int *installVector1,
               int *Imeasure,
               int *Imeasure_delta,
               int *gamma, int mdzmax)
/*@
With pdeltaZ_l q_l installVector1_l Imeasure_l Imeasure_delta_l gamma_v
Require store_int_ptr(pdeltaZ) && store_int_ptr(q) && store_int_ptr(installVector1) && store_int_ptr(Imeasure) && store_int_ptr(Imeasure_delta) && *(gamma) == gamma_v
Ensure emp
*/
{
    int Cq[9];
    int tmpZiGamma[3];
    int tmpV3a[3];
    int tmpV3b[3];
    int tmpV3c[3];
    int tmpZX[9];
    int deltaX1[3];
    int deltaY1[3];
    int deltaZ1[3];

    q_to_C(Cq, q);

    mat_mul(tmpV3a, Cq, &Imeasure[0 * 3], 3, 3, 1);
    mat_mul(tmpZX,  &installVector1[2 * 3], &installVector1[0 * 3], 3, 1, 3);
    mat_mul(tmpV3b, Cq, gamma, 3, 3, 1);
    mat_mul(tmpV3c, tmpZX, tmpV3b, 3, 3, 1);
    vec_sub(tmpV3a, tmpV3a, tmpV3c, 3);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[0 * 3], 3);
    vec_cross3(deltaX1, &installVector1[0 * 3], tmpV3a);

    mat_mul(tmpV3a, Cq, &Imeasure[1 * 3], 3, 3, 1);
    mat_mul(tmpZX,  &installVector1[2 * 3], &installVector1[1 * 3], 3, 1, 3);
    mat_mul(tmpV3c, tmpZX, tmpV3b, 3, 3, 1);
    vec_sub(tmpV3a, tmpV3a, tmpV3c, 3);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[1 * 3], 3);
    vec_cross3(deltaY1, &installVector1[1 * 3], tmpV3a);

    vec_add(tmpZiGamma, &Imeasure[2 * 3], gamma, 3);
    mat_mul(tmpV3a, Cq, tmpZiGamma, 3, 3, 1);
    vec_add(tmpV3a, tmpV3a, &Imeasure_delta[2 * 3], 3);
    vec_cross3(deltaZ1, &installVector1[2 * 3], tmpV3a);

    vec_add(pdeltaZ, deltaX1, deltaY1, 3);
    vec_add(pdeltaZ, pdeltaZ, deltaZ1, 3);
    vec_scale(pdeltaZ, pdeltaZ, 1, 3);  

    int tmpdZ = triple_fabs_max(pdeltaZ[0], pdeltaZ[1], pdeltaZ[2]);
    if (tmpdZ > mdzmax) {
        int tmpf = mdzmax / tmpdZ;
        pdeltaZ[0] = tmpf * pdeltaZ[0];
        pdeltaZ[1] = tmpf * pdeltaZ[1];
        pdeltaZ[2] = tmpf * pdeltaZ[2];
    }
    return;
}

void StsCompensate(int *pSTSdeltaZ, int *wGyro,
                   int *pSTSIV, int dtime)
/*@
With pSTSdeltaZ_l wGyro_l pSTSIV_v
Require store_int_ptr(pSTSdeltaZ) && store_int_ptr(wGyro) && *(pSTSIV) == pSTSIV_v
Ensure emp
*/
{
    int W[9];

    W[0] = 0;        W[1] = -wGyro[2]; W[2] =  wGyro[1];
    W[3] = wGyro[2];   W[4] =  0;       W[5] = -wGyro[0];
    W[6] = -wGyro[1];  W[7] =  wGyro[0];  W[8] =  0;

    mat_mul(pSTSdeltaZ, W, pSTSIV, 3, 3, 1);

    pSTSdeltaZ[0] = pSTSdeltaZ[0] * dtime;
    pSTSdeltaZ[1] = pSTSdeltaZ[1] * dtime;
    pSTSdeltaZ[2] = pSTSdeltaZ[2] * dtime;
    return;
}

void StsFilter(int *bi, int *q, int *pdeltaZ,
               int *KS, int mblimit)
/*@
With bi_l q_l pdeltaZ_v KS_v
Require store_int_ptr(bi) && store_int_ptr(q) && *(pdeltaZ) == pdeltaZ_v && *(KS) == KS_v
Ensure emp
*/
{
    int qb6[6];
    int Eq[12];
    int dq[4];

    mat_mul(qb6, KS, pdeltaZ, 6, 3, 1);
    q_to_Ksi(Eq, q);
    mat_mul(dq, Eq, qb6, 4, 3, 1);

   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= i && i <= n) &&
    (n == n@pre)
    */
for (unsigned int i = 0; i < 4; i++) {
        q[i] = q[i] + dq[i];
    }

    q_normalize(q);

   
  /*@ Inv
    exists  installVector1_l,    
    store_int_ptr(installVector1) &&
    (0 <= i && i <= n) &&
    (n == n@pre) &&
    (k == k@pre) &&
    (true)) &&
    (true)) &&
    (forall (j:Z), i <= j && j < n => out[j] == out[j]@pre)
    */
for (unsigned int i = 0; i < 3; i++) {
        bi[i] = bi[i] + qb6[i + 3];
        bi[i] = limit_abs(bi[i], mblimit);
    }
    return;
}

void CS_Sts_Gyro_Modify_Single_pipeline(
    int *installVector1,
    int *Imeasure,
    int *KS,
    int *wGyro,
    int *gamma,
    int dtime,
    int mdzmax,
    int mblimit,
    int *q,
    int *bi,
    int *dInno)

/*@
With installVector1_l Imeasure_v KS_v wGyro_v gamma_v q_v bi_v dInno_v
Require store_int_ptr(installVector1) && *(Imeasure) == Imeasure_v && *(KS) == KS_v && *(wGyro) == wGyro_v && *(gamma) == gamma_v && *(q) == q_v && *(bi) == bi_v && *(dInno) == dInno_v
Ensure emp
*/{
    int Imeasure_delta[9];

    StsCompensate(&Imeasure_delta[0 * 3], wGyro, &installVector1[0 * 3], dtime);
    StsCompensate(&Imeasure_delta[1 * 3], wGyro, &installVector1[1 * 3], dtime);
    StsCompensate(&Imeasure_delta[2 * 3], wGyro, &installVector1[2 * 3], dtime);

    StsModify(dInno, q, installVector1, Imeasure, Imeasure_delta, gamma, mdzmax);

    StsFilter(bi, q, dInno, KS, mblimit);
    return;
}