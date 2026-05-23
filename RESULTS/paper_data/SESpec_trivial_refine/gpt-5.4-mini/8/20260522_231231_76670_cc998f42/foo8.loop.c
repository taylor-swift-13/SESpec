int foo32_helper1_c8(int n, int m);
int foo32_helper2_c8(int n, int m);
int foo32_helper3_c8(int n);
int foo8(int n, int m);

#include <limits.h>

int foo32_helper1_c8(int n, int m);

/*@
  requires n != INT_MIN;
  requires m != INT_MIN;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo32_helper2_c8(int n, int m);

int foo32_helper3_c8(int n);
int foo8(int n, int m);

int foo32_helper2_c8(int n, int m) {

    if (m < 0) {
      return foo32_helper2_c8(n, -m);
    }
    if (n < 0) {
      return foo32_helper2_c8(-n, m);
    }
    if (m == 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    return foo32_helper2_c8(n - m, m);
}


int foo8(int n, int m) {

    if (n <= 1) {
      return 0; // 0
    } else if (n == 2) {
      return 1; // 1
    } else {
      if (m <= 1) {
        return 1; // 1
      } else {
        if (foo32_helper2_c8(n, m) == 0) {
          return 0; // 0
        }
        return foo8(n, m - 1);
      }
    }
}