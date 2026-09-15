
#include <stdlib.h>

int unknown();

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
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant i == 1 + 2 * a;
      loop invariant j >= 1 + a;
      loop invariant a == 0 || i > 1;
      loop invariant a == 0 || j > 1;
      loop invariant b <= a * (j + i);
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
