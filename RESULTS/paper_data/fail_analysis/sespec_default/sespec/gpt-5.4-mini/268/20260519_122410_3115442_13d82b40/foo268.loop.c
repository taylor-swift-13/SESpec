
#include <stdlib.h>

int foo268(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		
            
        /*@
          loop invariant \forall integer i; 3 <= i < d ==> div[i] < result;
          loop assigns d, div[3..count];
        */
            for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
            
		return div[count];
}
