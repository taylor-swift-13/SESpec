#include <limits.h>


/*@
  requires n >= 0;
  decreases n;
  assigns \nothing;
*/

  logic integer foo2_spec(integer n) =
    n < 1 ? 0 :
    n == 1 ? 1 :
    foo2_spec(n - 1) + foo2_spec(n - 2);

/*@requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures n < 1 ==> \result == 0;
  ensures n == 1 ==> \result == 1;
  ensures n > 1 ==> \result == foo2_spec(n);
  ensures \result == 0 || \result == 1 || \result > 1;*/
int stub_A(int n);

/*@requires n >= 0;
ensures n >= 2 ==> \result >= 1;
ensures n >= 2 ==> \result >= 0;
ensures n == 1 ==> \result == 1;
ensures n == 0 ==> \result == 0;
assigns \nothing;*/
int stub_B(int n);

/*@requires n >= 0;
ensures n >= 2 ==> \result >= 1;
ensures n >= 2 ==> \result >= 0;
ensures n == 1 ==> \result == 1;
ensures n == 0 ==> \result == 0;
assigns \nothing;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures n < 1 ==> \result == 0;
  ensures n == 1 ==> \result == 1;
  ensures n > 1 ==> \result == foo2_spec(n);
  ensures \result == 0 || \result == 1 || \result > 1;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
