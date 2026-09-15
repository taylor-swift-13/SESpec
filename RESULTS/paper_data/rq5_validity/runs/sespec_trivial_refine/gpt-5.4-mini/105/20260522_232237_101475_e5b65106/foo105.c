
#include <stdlib.h>

/*@ logic integer fibo(integer n) =
      n <= 0 ? 0 : (n == 1 ? 1 : fibo(n - 1) + fibo(n - 2)); */
/*@
  requires 0 <= n <= 46;
  assigns \result \from n;
  ensures n == 0 ==> \result == 0;
  ensures (n == 1 || n == 2) ==> \result == 1;
  ensures n >= 3 ==> \result > 0;
*/
int foo105(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 0;
    int b = 1;
    int i = 2;

    /*@
      loop invariant 2 <= i <= n;
      loop invariant a >= 0;
      loop invariant b >= 1;
      loop invariant i >= 2;
      loop assigns a, b, i;
      loop variant n - i;
    */
    while (i < n) {
        int c = a + b;
        a = b;
        b = c;
        i++;
    }

    return b;
}
