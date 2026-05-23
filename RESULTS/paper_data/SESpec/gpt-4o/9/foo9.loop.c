#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);
int foo9(int m, int n);

#include <assert.h>

/*@ 
  // Define the logic function `foo36_logic` to represent the recursive behavior of `foo36_helper1_c9`.
  logic integer foo36_logic(integer m, integer n, integer c) =
    (n == 0) ? m :
    (c >= 150) ? -1 : // Represents an invalid state (assertion failure).
    (n > 0) ? foo36_logic(m + 1, n - 1, c + 1) :
              foo36_logic(m - 1, n + 1, c + 1);
*/

/*@ 
  requires c < 150; // The input `c` must be less than 150.
  decreases n >= 0 ? n : -n; // The absolute value of `n` strictly decreases with each recursive call.
  assigns \nothing; // The function does not modify any caller-visible state.
  ensures (n == 0) ==> (\result == m); // If `n` is 0, the result is `m`.
  ensures (n != 0 && c < 150) ==> (\result == foo36_logic(m, n, c)); // Otherwise, the result matches the logic function.
*/
int foo36_helper1_c9(int m, int n, int c) {
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}


int foo9(int m, int n) {
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}