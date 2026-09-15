
/*@
  // Define the logic function product_mod_10
  logic integer product_mod_10(integer start, integer end) =
    (start > end) ? 1 : (start % 10) * product_mod_10(start + 1, end) % 10;
*/

/*@
  requires n <= c; // Ensure the range [n + 1, c] is well-defined
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures (c - n) >= 5 ==> \result == 0;
*/
int foo333(int n, int c) {

    int result = 1;
    if (n == c) {
        return 1;
    } else if ((c - n) >= 5) {
        return 0;
    } else {
        /*@
          loop invariant c == \at(c, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant n + 1 <= var <= c + 1;
          loop invariant var == n + 1 ==> result == 1;
          loop assigns var, result;
          loop variant c - var;
        */
        for (int var = n + 1; var < c + 1; var++) {
            result = (result * (var % 10)) % 10;
        }
        
        return result % 10;
    }
}
