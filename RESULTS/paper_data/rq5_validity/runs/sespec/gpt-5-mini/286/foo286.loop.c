
/*@
  logic integer fib_like(integer n) =
    n == 0 ? 0
  : n == 1 ? 1
  : fib_like(n-1) + 2 * fib_like(n-2);
*/

/*@
  requires j >= 1;
  ensures \result == fib_like(j);
  assigns \nothing;
*/
int foo286(int j) {

    int *r = (int *)malloc(sizeof(int) * (j + 1));
    int r_len = j + 1;
    r[0] = 0;
    r[1] = 1;
        
    /*@
      loop invariant 2 <= p <= j + 1;
      loop assigns p, r[0..j];
    */
    for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1] + 2 * r[p - 2];
    }
            
    return r[j];
}
