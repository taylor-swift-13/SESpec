
#include <limits.h>

void foo64() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;

    /*@
      loop invariant 0 <= a;
      loop invariant i == 1 + 2 * a;
      loop invariant j == 1 + a;
      loop invariant i - j == a;
      loop invariant i % 2 == 1;
      loop invariant j >= 1;
      loop invariant b <= 0;
      loop invariant 2 * b + a * (a - 1) == 0;
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= a;
      loop invariant b <= 0;
      loop assigns a, b, i, j;
    */
    while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
           j = j + 2;
       }
       else{
           j = j + 1;
       }
    }
}
