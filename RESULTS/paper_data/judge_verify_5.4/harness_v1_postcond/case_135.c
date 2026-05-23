#include <limits.h>




/*@ logic integer ipow(integer x, integer n) =
      n <= 0 ? 1 : x * ipow(x, n - 1); */

/*@requires n >= 0;
  assigns \nothing;
  ensures \result == ipow(x, n);
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == x * ipow(x, n - 1);
  ensures x == 1 ==> \result == ipow(x, n);
  ensures x == 0 && n > 0 ==> \result == 0;*/
int stub_A(int x, int n);

/*@loop invariant x == x;
        loop invariant x == 1 ==> res == 1;
        loop invariant x == 0 || res != 0;
        loop invariant x == 0 ==> res == 0 || i == 0;
        loop invariant x == 0 ==> (i > 0 ==> res == 0);
        loop invariant x == 0 ==> (i == 0 || res == 0);
        loop invariant x != 0 ==> res != 0;
        loop invariant x != 0 ==> res != 0 || i == 0;
        loop invariant res == x == 0 || res != 0;
        loop invariant res == 1 || x == 0 || x != 0;
        loop invariant res == 1 || x == 0 || res != 0;
        loop invariant res == 1 || res == x || res != 0;
        loop invariant res == 1 || res == 0 || x != 0;
        loop invariant res == 1 || i > 0;
        loop invariant res == 0 ==> x == 0;
        loop invariant res != 0 || x == 0;
        loop invariant res != 0 ==> x != 0 || i == 0;
        loop invariant res != 0 ==> (x != 0 || i == 0);
        loop invariant n >= 0 || i == 0;
        loop invariant n >= 0 ==> res != 0 || x == 0;
        loop invariant n >= 0 ==> i <= n;
        loop invariant n == 0 ==> res == 1;
        loop invariant i > 0 ==> res == x || res == res;
        loop invariant i > 0 ==> res == x || res != 0;
        loop invariant i > 0 ==> res == 0 || res != 0;
        loop invariant i > 0 ==> res != 0 || x == 0;
        loop invariant i == n ==> res == res;
        loop invariant i == 0 ==> res == 1;
        loop invariant 0 <= i;
        loop assigns res;
        loop assigns i;*/
int stub_B(int x, int n);

/*@loop invariant x == x;
        loop invariant x == 1 ==> res == 1;
        loop invariant x == 0 || res != 0;
        loop invariant x == 0 ==> res == 0 || i == 0;
        loop invariant x == 0 ==> (i > 0 ==> res == 0);
        loop invariant x == 0 ==> (i == 0 || res == 0);
        loop invariant x != 0 ==> res != 0;
        loop invariant x != 0 ==> res != 0 || i == 0;
        loop invariant res == x == 0 || res != 0;
        loop invariant res == 1 || x == 0 || x != 0;
        loop invariant res == 1 || x == 0 || res != 0;
        loop invariant res == 1 || res == x || res != 0;
        loop invariant res == 1 || res == 0 || x != 0;
        loop invariant res == 1 || i > 0;
        loop invariant res == 0 ==> x == 0;
        loop invariant res != 0 || x == 0;
        loop invariant res != 0 ==> x != 0 || i == 0;
        loop invariant res != 0 ==> (x != 0 || i == 0);
        loop invariant n >= 0 || i == 0;
        loop invariant n >= 0 ==> res != 0 || x == 0;
        loop invariant n >= 0 ==> i <= n;
        loop invariant n == 0 ==> res == 1;
        loop invariant i > 0 ==> res == x || res == res;
        loop invariant i > 0 ==> res == x || res != 0;
        loop invariant i > 0 ==> res == 0 || res != 0;
        loop invariant i > 0 ==> res != 0 || x == 0;
        loop invariant i == n ==> res == res;
        loop invariant i == 0 ==> res == 1;
        loop invariant 0 <= i;
        loop assigns res;
        loop assigns i;*/
int check_A_implies_B(int x, int n) {
    return stub_A(x, n);
}

/*@requires n >= 0;
  assigns \nothing;
  ensures \result == ipow(x, n);
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == x * ipow(x, n - 1);
  ensures x == 1 ==> \result == ipow(x, n);
  ensures x == 0 && n > 0 ==> \result == 0;*/
int check_B_implies_A(int x, int n) {
    return stub_B(x, n);
}
