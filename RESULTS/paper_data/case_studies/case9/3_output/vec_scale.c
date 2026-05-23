
/*@
  requires \valid(&out[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires \valid(&A[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
*/

void vec_scale(int *out, int *A, int k, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
      loop invariant k == \at(k, Pre);
      loop invariant \valid(out + (0..n-1));
      loop invariant \valid(A + (0..n-1));
      loop invariant \forall integer j; i <= j < n ==> out[j] == \at(out[j], Pre);
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] * k;
    }
    return;
}
