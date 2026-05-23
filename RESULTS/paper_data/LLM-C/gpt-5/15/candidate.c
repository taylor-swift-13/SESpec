#include <stdlib.h>

/*@ 
  requires \true;

  assigns \nothing;

  ensures size < 0 ==> \result == -1;
  ensures 0 <= size < 4 ==> \result == 1;
  ensures size >= 4 ==> \result == 0;
*/
int func(int size);

/*@ 
  requires \true;

  assigns \nothing;

  behavior neg:
    assumes size < 0;
    assigns \nothing;
    ensures \result == -1;

  behavior inrange:
    assumes 0 <= size < 4;
    assigns \nothing;
    ensures \result == 1;

  behavior big:
    assumes size >= 4;
    assigns \nothing;
    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int func(int size) {
    if (size < 0) return -1;
    if (size < 0 || size >= 4) return 0;
    int *a = (int *)malloc(sizeof(int) * 4);
    a[size] = 0;
    return 1;
}
