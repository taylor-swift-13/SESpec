
#include <limits.h>

/*@
  requires num > 0;
  ensures \result >= 0;
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
      loop invariant \forall integer k; 2 <= k < size ==> (num % k == 0 ==> \exists integer r; r >= 0 && r == result);
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
