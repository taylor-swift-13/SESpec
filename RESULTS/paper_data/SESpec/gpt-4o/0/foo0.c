
/*@ 
  logic integer foo0_logic(integer m, integer n) =
    m == 0 ? n + 1 :
    n == 0 ? foo0_logic(m - 1, 1) :
             foo0_logic(m - 1, foo0_logic(m, n - 1));
*/

/*@
  requires m >= 0;
  requires n >= 0;
  decreases m;
  assigns \nothing;
  ensures \result == foo0_logic(m, n);
*/
int foo0(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return foo0(m - 1, 1);
    }
    return foo0(m - 1, foo0(m, n - 1));
}
