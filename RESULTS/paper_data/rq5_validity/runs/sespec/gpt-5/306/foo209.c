
#include <stddef.h>
#include <stdlib.h>

/*@ logic integer lucas_val(integer k) =
      k == 0 ? 2 :
      k == 1 ? 1 :
      k >= 2 ? lucas_val(k - 1) + lucas_val(k - 2) :
      0; */

/*@
  requires n >= 1;
  requires n <= 45;
*/
int foo209(int n) {

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant lucas_len == n + 1;
          loop invariant 2 <= i;
          loop invariant (i <= n) ==> i + 1 <= lucas_len;
          loop invariant lucas[0] == lucas_val(0);
          loop invariant lucas[1] == lucas_val(1);
          loop invariant (i <= n) ==> (lucas[i - 1] == lucas_val(i - 1) && lucas[i - 2] == lucas_val(i - 2));
          loop assigns i, lucas[0 .. lucas_len - 1];
            */
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
            
        return lucas[n];
}
