
#include <limits.h>

/*@ 
  logic integer count_divisors(integer n) = 
    \sum(2, n / 2, \lambda integer k; (n % k == 0 ? 1 : 0));
*/
/*@
  requires num > 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures num == 1 ==> \result == 1;
*/
int foo317(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= size <= num + 1;
      loop invariant result >= 0;
      loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> k * (num / k) == num);
      loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> num / k >= k);
      loop assigns size, result;
    */
    for (int size = 2; size <= num / size; size++) {
        if (num % size == 0) {
            result++;
            if (num / size == size) {
                break;
            }
        }
    }

    return result;
}
