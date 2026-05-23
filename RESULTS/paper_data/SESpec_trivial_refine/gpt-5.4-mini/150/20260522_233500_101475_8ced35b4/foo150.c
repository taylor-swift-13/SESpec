
#include <stdlib.h>

/*@
  requires 0 <= value;
  requires 0 <= p;
  assigns \result \from value, p;

  behavior out_of_range:
    assumes p == 0 || p > value;
    ensures \result == 0;

  behavior odd_case:
    assumes 1 <= p <= (value + 1) / 2;
    ensures \result == 2 * p - 1;

  behavior even_case:
    assumes (value + 1) / 2 < p <= value;
    ensures \result == 2 * (p - (value + 1) / 2);

  complete behaviors;
  disjoint behaviors;
*/
int foo150(int value, int p) {
  if (p == 0 || p > value) {
    return 0;
  }

  if (p <= (value + 1) / 2) {
    return 2 * p - 1;
  }

  return 2 * (p - (value + 1) / 2);
}
