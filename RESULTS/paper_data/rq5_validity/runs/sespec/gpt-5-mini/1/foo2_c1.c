
/*@
  logic integer abs(integer x) = x >= 0 ? x : -x;
*/

/*@ 
  logic integer foo2_c1_spec(integer m, integer n) =
    n == 0 ? m : (n > 0 ? foo2_c1_spec(m + 1, n - 1) : foo2_c1_spec(m - 1, n + 1));
*/

/*@
  requires \true;
  decreases abs(n);
  assigns \nothing;
  ensures \result == foo2_c1_spec(m, n);
  ensures \result == m + n;
*/
int foo2_c1(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo2_c1(m + 1, n - 1);
        } else {
            return foo2_c1(m - 1, n + 1);
        }
}
