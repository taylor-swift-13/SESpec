
/*@
  requires \valid(&out[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= out[i] <= 100;
  requires n > 0;
  requires n < 100;
  requires \valid(&A[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= A[i] <= 100;
  requires \valid(&B[0] + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 0 <= B[i] <= 100;
  requires \separated(out + (0..n-1), A + (0..n-1));
  requires \separated(out + (0..n-1), B + (0..n-1));
  assigns out[0..n-1], A[0..n-1], B[0..n-1];
*/
void vec_add(int *out, int *A, int *B, int n)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
    */
    for (int i = 0; i < n; i++) {
        out[i] = A[i] + B[i];
    }
    return;
}
