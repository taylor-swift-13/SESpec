#include <limits.h>

int sumDiv(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == \sum(integer i, 1, number/2, ((\exists integer k; number == k*i) ? i : 0));
  ensures \result >= 0;
*/
int sumDiv(int number) {

        int sum = 0;
        /*@
          loop invariant 1 <= i;
          loop invariant 0 <= sum;
          loop invariant sum == \sum(integer j, 1, i-1, ((\exists integer k; number == k*j) ? j : 0));
          loop assigns sum, i;
          loop variant (number/2 - i + 1 >= 0 ? number/2 - i + 1 : 0);
        */
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
}
