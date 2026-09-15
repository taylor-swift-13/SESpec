
/*@
  logic integer compute_W(int* W, int* C, integer w) =
    w == 0 ? 1 :
    w == 1 ? 0 :
    compute_W(W, C, w - 2) + 2 * compute_C(W, C, w - 1);

  logic integer compute_C(int* W, int* C, integer w) =
    w == 0 ? 0 :
    w == 1 ? 1 :
    compute_W(W, C, w - 1) + compute_C(W, C, w - 2);
*/

/*@
  requires count >= 0;
  requires \valid(W + (0..count));
  requires \valid(C + (0..count));
  ensures \result == compute_W(W, C, count);
  assigns W[0..count], C[0..count];
*/
int foo191(int count) {
    int *W = (int *)malloc(sizeof(int) * (count + 1));
    int W_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    W[0] = 1;
    W[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
      loop invariant 2 <= w <= count + 1;
      loop invariant \forall integer k; 0 <= k < w ==> W[k] == compute_W(W, C, k);
      loop invariant \forall integer k; 0 <= k < w ==> C[k] == compute_C(W, C, k);
      loop assigns w, W[0..count], C[0..count];
      loop variant count - w;
    */
    for (int w = 2; w <= count; w++) {
        W[w] = W[w - 2] + 2 * C[w - 1];
        C[w] = W[w - 1] + C[w - 2];
    }

    return W[count];
}
