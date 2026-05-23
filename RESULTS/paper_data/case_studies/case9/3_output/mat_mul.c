
/*@
  logic integer mat_sum(int *A, int *B, integer ca_rb, integer cb,
                        integer i, integer j, integer k) =
    k <= 0 ? 0 :
    mat_sum(A, B, ca_rb, cb, i, j, k - 1) +
    A[i * ca_rb + (k - 1)] * B[(k - 1) * cb + j];
*/
        
/*@
  requires \valid(&out[0] + (0..ra * cb-1));
  requires \forall integer i; 0 <= i < ra * cb ==> 0 <= out[i] <= 100;
  requires ra * cb > 0;
  requires ra * cb < 100;
  requires \valid(&A[0] + (0..ra * ca_rb-1));
  requires \forall integer i; 0 <= i < ra * ca_rb ==> 0 <= A[i] <= 100;
  requires ra * ca_rb > 0;
  requires ra * ca_rb < 100;
  requires \valid(&B[0] + (0..ca_rb * cb-1));
  requires \forall integer i; 0 <= i < ca_rb * cb ==> 0 <= B[i] <= 100;
  requires ca_rb * cb > 0;
  requires ca_rb * cb < 100;
*/
void mat_mul(int *out, int *A, int *B,
             int ra, int ca_rb, int cb)
{
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant i == 0 || (0 <= i <= ra);
      loop invariant \true;
      loop invariant cb == \at(cb,Pre);
      loop invariant ca_rb == \at(ca_rb,Pre);
      loop invariant ra == \at(ra,Pre);
      loop invariant B == \at(B,Pre);
      loop invariant A == \at(A,Pre);
      loop invariant out == \at(out,Pre);
      loop assigns i, out[0..ra * cb - 1];
    */
    for (int i = 0; i < ra; i++) {
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= j <= cb;
          loop invariant \true;
          loop assigns j, out[i * cb .. i * cb + cb - 1];
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
            for (int k = 0; k < ca_rb; k++) {
                s = s + A[i * ca_rb + k] * B[k * cb + j];
            }
            
            out[i * cb + j] = s;
        }
    }
            
    return;
}
