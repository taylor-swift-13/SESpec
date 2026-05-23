#include <stddef.h>

/*@ logic integer pow4(integer k) = (k <= 0) ? 1 : 4 * pow4(k - 1); */

int isPowerOfFour(int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures 0 <= \result <= 1;
  ensures (\result == 1) <=> (\exists integer k; k >= 0 && \at(n,Pre) == pow4(k));
  ensures (\at(n,Pre) > 0) ==> (n >= 1 && n % 4 != 0);
  terminates \true;
*/
int isPowerOfFour(int n) {

        if(n <= 0) {
            return 0;
        }
        /*@
          loop invariant n > 0;
          loop invariant \exists integer k; k >= 0 && \at(n,Pre) == n * pow4(k);
          loop assigns n;
          loop variant n;
        */
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}
