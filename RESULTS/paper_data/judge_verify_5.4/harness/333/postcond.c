#include <limits.h>

/*@ logic integer tenprod(integer n, integer c) =
    n >= c ? 1 : ((n % 10) * tenprod(n + 1, c)) % 10; */

/*@ ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  assigns \nothing; */
int stub_A(int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n, int c);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n, int c) {
    return stub_A(n, c);
}

/*@ ensures n == c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  assigns \nothing; */
int check_B_implies_A(int n, int c) {
    return stub_B(n, c);
}
