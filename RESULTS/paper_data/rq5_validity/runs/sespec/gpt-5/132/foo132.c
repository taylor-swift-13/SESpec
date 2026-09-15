
#include <limits.h>

/*@
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] >= \result;
  ensures a_len > 0 ==> \result >= INT_MIN;
  ensures a_len > 0 ==> \result <= INT_MAX;
  ensures a_len > 0 ==> \result <= a[0];
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
  assigns \nothing;
*/
int foo132(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        /*@
          loop invariant res <= INT_MAX;
          loop invariant res >= INT_MIN;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] >= res;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, res;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }

        return res;
}
