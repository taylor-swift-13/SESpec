
/*@ 
  logic integer foo27_c5_spec(integer n) =
    n > 100 ? n - 10 : 91;
*/

/*@
  requires n >= -2147483648;
  decreases n > 100 ? 0 : 101 - n;
  assigns \nothing;
  ensures \result == foo27_c5_spec(n);
  ensures (n > 100 ==> \result == n - 10) && (n <= 100 ==> \result == 91);
*/
int foo27_c5(int n);

int foo27_c5(int n) {
    if (n > 100) return n - 10;
    else return foo27_c5(foo27_c5(n + 11));
}
