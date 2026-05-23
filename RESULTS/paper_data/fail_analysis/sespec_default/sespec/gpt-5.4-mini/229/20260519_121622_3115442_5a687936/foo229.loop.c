
#include <stdlib.h>

/*@ logic integer sum(int* a, integer lo, integer hi) =
      lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        


int foo229(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant arr[0] == 1;
              loop assigns d, arr[0 .. seed];
            */
            for (int d = 1; d <= seed; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= c;
              loop invariant arr[0] == 1;
              loop assigns c, arr[d];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
