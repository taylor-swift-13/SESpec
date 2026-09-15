
#include <limits.h>

/*@ 
  requires a_len >= 0;
  requires \valid_read(a + (0..a_len-1));
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] >= \result;
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
*/
int foo132(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res <= INT_MAX;
          loop invariant res >= INT_MIN;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] >= res;
          loop invariant i == 0 ==> res == INT_MIN;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant (!(i < a_len)) ==> (i == a_len);
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
            
        return res;
}
