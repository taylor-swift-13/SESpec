#include <limits.h>
#include <stdlib.h>

/*@ logic integer fibo(integer n) =
      n <= 1 ? n : fibo(n - 1) + fibo(n - 2); */

/*@ ensures n < 0 ==> \result == -1;
  ensures n == 0 ==> \result == 0; */
int stub_A(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ ensures n < 0 ==> \result == -1;
  ensures n == 0 ==> \result == 0; */
int check_B_implies_A(int n) {
    return stub_B(n);
}
