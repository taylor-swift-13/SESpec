#include <stdlib.h>

int foo17(int index);


/*@
  requires \true;
  assigns \nothing;
  ensures (index < 0 || index >= 4) ==> \result == 0;
  ensures 0 <= index < 4 ==> \result == 1;
*/
int foo17(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}