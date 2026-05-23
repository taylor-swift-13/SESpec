
#include <limits.h>

int unknown(void);

/*@
  predicate even(int x) = x % 2 == 0;
*/


void foo63() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

    /*@
      loop invariant  a >= 0;                         // a counts iterations
      loop invariant  even(i);                       // i stays even
      loop invariant  i >= 0;                        // i non-negative and grows
      loop invariant  j == i + 1;                    // j always equals i+1
      loop invariant  b == a;                        // each iteration adds (j - i)==1 to b
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
