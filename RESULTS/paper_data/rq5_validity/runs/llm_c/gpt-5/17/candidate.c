#include <stdlib.h>

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int func(int index);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int func(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}
