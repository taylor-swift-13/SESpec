
/*@
  logic integer product_mod_10(integer a, integer b) =
    (a > b) ? 1 : (a % 10) * product_mod_10(a + 1, b) % 10;
*/

/*@
  requires n >= 0 && c >= 0;
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures (c - n) >= 5 ==> \result == 0;
*/
int foo167(int n, int c) {

    int result = 1;
    if (n == c) {
        return 1;
    } else if ((c - n) >= 5) {
        return 0;
    } else {
        
        /*@
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns index, result;
          loop variant c - index;
        */
        for (int index = n + 1; index < c + 1; index++) {
            result = (result * (index % 10)) % 10;
        }
        
        return result % 10;
    }
}
