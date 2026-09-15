
#include <stdlib.h>

int foo268(int count, int w) {

    int result = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (count + 1));
    int div_len = count + 1;
    div[0] = 1;
    div[1] = w;
    div[2] = w * w;
        
    /*@
      loop invariant 3 <= d;
      loop invariant div[0] == 1;
      loop invariant div[1] == w;
      loop invariant d >= 2 ==> div[2] == w * w;
      loop invariant \forall integer k; 0 <= k < div_len ==> (k < d || k <= 2) ==> ( (k == 0 ==> div[0] == 1) && (k == 1 ==> div[1] == w) && (k == 2 ==> (div[2] == w * w || d <= 2)) );
      loop invariant \forall integer k; 3 <= k < d ==> (k-1 >= 0 && k-2 >= 0 && k-1 < d && k-2 < d);
      loop invariant \forall integer k; 0 <= k < div_len ==> (k > count ==> div[k] == div[k]);
      loop assigns d, div[0..count];
    */
    for (int d = 3; d <= count; d++) {
        div[d] = ((w - 1)
                * (div[d - 1] + div[d - 2])) % result;
    }
            
    return div[count];
}
