#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (mat_sum : Z -> Z -> Z -> Z -> Z -> Z -> Z -> Z) */

void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
/*@
With out_l A_l B_l
Require store_int_array(out, ra * cb, out_l) && ra * cb > 0 && ra * cb < 100 && store_int_array(A, ra * ca_rb, A_l) && ra * ca_rb > 0 && ra * ca_rb < 100 && store_int_array(B, ca_rb * cb, B_l) && ca_rb * cb > 0 && ca_rb * cb < 100
Ensure emp
*/
{
   
  /*@ Inv
    exists  pSTSdeltaZ_l wGyro_l,    
    store_int_ptr(pSTSdeltaZ) && store_int_ptr(wGyro) &&
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
    exists  pSTSdeltaZ_l wGyro_l,    
    store_int_ptr(pSTSdeltaZ) && store_int_ptr(wGyro) &&
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
    exists  pSTSdeltaZ_l wGyro_l,    
    store_int_ptr(pSTSdeltaZ) && store_int_ptr(wGyro) &&
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

void StsCompensate(int *pSTSdeltaZ, int *wGyro,
                   int *pSTSIV, int dtime)

/*@
With pSTSdeltaZ_l wGyro_l pSTSIV_v
Require store_int_ptr(pSTSdeltaZ) && store_int_ptr(wGyro) && *(pSTSIV) == pSTSIV_v
Ensure emp
*/{
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