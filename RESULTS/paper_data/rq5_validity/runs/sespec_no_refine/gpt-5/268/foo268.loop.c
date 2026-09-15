
#include <stdlib.h>

/*@
  // No additional logic functions are required.
*/

int foo268(int count, int w) {

    int result = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (count + 1));
    int div_len = count + 1;
    div[0] = 1;
    div[1] = w;
    div[2] = w * w;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 3 <= d <= count + 1;
      loop invariant \valid(div + (0 .. count));
      loop invariant div_len == count + 1;
      loop invariant div[0] == 1;
      loop invariant div[1] == w;
      loop invariant div[2] == w * w;
      loop invariant \forall integer k; 3 <= k < d ==>
                        div[k] == (((w - 1) * (div[k - 1] + div[k - 2])) % result);
      loop assigns d, div[0 .. count];
    */
    for (int d = 3; d <= count; d++) {
        div[d] = ((w - 1)
                * (div[d - 1] + div[d - 2])) % result;
    }
            
    return div[count];
}
