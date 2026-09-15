
/*@
  logic integer sum_of_powers(integer n) = 
    n <= 0 ? 0 : (2 * n) * (2 * n) * (2 * n) * (2 * n) + sum_of_powers(n - 1);
*/

/*@
  requires p >= 0;
  assigns \nothing;
  ensures \result == sum_of_powers(p);
*/
int foo322(int p) {

    int even = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant even == sum_of_powers(c - 1);
      loop invariant p == \at(p,Pre);
      loop assigns c, count, even;
    */
    for (int c = 1; c <= p; c++) {
        int count = 2 * c;
        even = even + (count * count * count * count);
    }

    return even;
}
