int foo1(int m, int n);


/*@ logic integer foo1_logic(integer m, integer n) =
      n == 0 ? m : (n > 0 ? foo1_logic(m + 1, n - 1) : foo1_logic(m - 1, n + 1));
*/
/*@
  requires \true;
  decreases \abs(n);
  assigns \nothing;
  ensures \result == foo1_logic(m, n);
  ensures n == 0 ==> \result == m;
  ensures n > 0 ==> \result == m + n;
  ensures n < 0 ==> \result == m + n;
*/
int foo1(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo1(m + 1, n - 1);
        } else {
            return foo1(m - 1, n + 1);
        }
}