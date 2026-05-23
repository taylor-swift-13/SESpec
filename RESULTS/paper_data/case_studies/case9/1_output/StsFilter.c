#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

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

void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
/*@
With out_l A_l B_l
Require store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  out_l A_l B_l,    
    store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100 &&
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
    exists  out_l A_l B_l,    
    store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100 &&
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
    exists  out_l A_l B_l,    
    store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100 &&
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

void StsFilter(int *bi, int *q, int *pdeltaZ,
               int *KS, int mblimit)

/*@
With bi_l q_l pdeltaZ_v KS_v
Require store_int_ptr(bi) && store_int_ptr(q) && *(pdeltaZ) == pdeltaZ_v && *(KS) == KS_v
Ensure emp
*/{
    int qb6[6];
    int Eq[12];
    int dq[4];

    mat_mul(qb6, KS, pdeltaZ, 6, 3, 1);
    q_to_Ksi(Eq, q);
    mat_mul(dq, Eq, qb6, 4, 3, 1);

    for (unsigned int i = 0; i < 4; i++) {
        q[i] = q[i] + dq[i];
    }

    q_normalize(q);

    for (unsigned int i = 0; i < 3; i++) {
        bi[i] = bi[i] + qb6[i + 3];
        bi[i] = limit_abs(bi[i], mblimit);
    }
    return;
}