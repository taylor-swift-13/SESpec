
/*@
  requires \valid(&out[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires \valid(&A[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
  requires \valid(&B[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= B[i] <= 100;
*/

void vec_sub(int *out, int *A, int *B, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; i <= k < n ==> out[k] == \at(out[k], Pre);
      loop assigns i, out[0..n-1];
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] - B[i];
    }
    return;
}
