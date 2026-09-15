#include <stdlib.h>

int foo17(int index);


/*@
  
  ensures (\result == 0) <==> (index < 0 || index >= 4);
  ensures (\result == 1) <==> (0 <= index && index < 4);
  ensures \result == 1 ==> (index >= 0 && index <= 3);
  ensures \result == 0 ==> (index < 0 || index >= 4);
*/
int foo17(int index) {
    if (index < 0 || index >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[index] = 0;
    return 1;
}