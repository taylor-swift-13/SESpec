
#include <stdlib.h>

/*@
  assigns \nothing;
  
*/
int foo293(int seed) {

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 0;
		arr[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p;
          loop invariant arr[0] == 0;
          loop invariant arr[1] == 1;
          loop invariant \forall integer i; 0 <= i < p ==> arr[i] == (i <= 1 ? i : (2 * arr[i - 1] + arr[i - 2]) % 1000000000);
          loop assigns p, arr[0..seed];
            */
            for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
            
		return arr[seed];
}
