#include <stdlib.h>

/*@ 
  requires \true;
  assigns \nothing;
  behavior neg:
    assumes size < 0;
    ensures \result == -1;
  behavior inrange:
    assumes 0 <= size < 4;
    ensures \result == 1;
  behavior outofrange:
    assumes size >= 4;
    ensures \result == 0;
  complete behaviors;
  disjoint behaviors;
*/
int func(int size);

int func(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    /*@ 
      assigns \nothing; 
    */
    int *a = (int *)malloc(sizeof(int) * 4);
    /*@ 
      requires 0 <= size < 4;
      requires a != \null;
      requires \valid(a + (0..3));
      assigns \nothing;
    */
    int i = a[size];
    (void)i;
    return 1;
}
