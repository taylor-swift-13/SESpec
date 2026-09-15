
/*@
  logic integer powi(integer a, integer n) =
    n <= 0 ? 1 : a * powi(a, n - 1);

  logic integer parity_sign(integer n) = (n % 2 == 0) ? 1 : -1;

  // Closed form for the sequence: r[0]=0, r[1]=1, r[k]=r[k-1]+2*r[k-2]
  logic integer closed_form(integer k) = (powi(2, k) - parity_sign(k)) / 3;
*/

int foo286(int j) {

    int *r = (int *)malloc(sizeof(int) * (j + 1));
    int r_len = j + 1;
    r[0] = 0;
    r[1] = 1;
        
    /*@
      loop invariant \valid(r + (0 .. r_len - 1));
      loop invariant r_len == j + 1;
      loop invariant 2 <= p <= j + 1;
      loop invariant r[0] == 0;
      loop invariant r[1] == 1;
      loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k-1] + 2 * r[k-2];
      loop invariant \forall integer k; 0 <= k < p ==> r[k] == closed_form(k);
      loop assigns p, r[..];
    */
    for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1]
                + 2 * r[p - 2];
    }
        
    return r[j];
}
