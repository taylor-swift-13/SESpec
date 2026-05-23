
#include <stdlib.h>

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        



int foo150(int value, int p) {

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
		int c, j = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= value;
          loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
          loop assigns c, result[..];
            */
            for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= value;
          loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
          loop invariant \forall integer k; 0 <= k < value ==> result[k] == k + 1;
          loop assigns c, b[..], j;
            */
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= value;
          loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
          loop invariant \forall integer k; 0 <= k < value ==> result[k] == k + 1;
          loop assigns c, b[..], j;
            */
            for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
            
		return 0;
}
