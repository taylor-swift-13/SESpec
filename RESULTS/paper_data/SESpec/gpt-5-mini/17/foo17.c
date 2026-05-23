#include <stdlib.h>

int foo17(int index);


/*@
  requires index < 0 || index >= 4;
  assigns \nothing;
  ensures (index < 0 || index >= 4) ==> \result == 0;
  ensures 0 <= index && index < 4 ==> \result == 1;
  ensures \result == 0 ==> \old(index) < 0 || \old(index) >= 4;
  ensures \result == 1 ==> 0 <= \old(index) && \old(index) < 4;
*/
int foo17(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}