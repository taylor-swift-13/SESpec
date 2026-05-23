
#include <stdlib.h>

/* No extra logic/predicate needed */

/*@ 
  requires Array >= 0;
  requires \valid_read(args + (0..Array-1));
   
*/
int foo154(int * args, int args_len, int Array) {

	int *mpis = (int *)malloc(sizeof(int) * (Array));
	int mpis_len = Array;
		
    /* >>> LOOP INVARIANT REGENERATED <<< */
        
    /*@
      loop invariant 0 <= array <= Array;
      loop invariant \valid_read(args + (0..array-1));
      loop invariant (!(array < Array)) ==> (array == Array);
      loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
		mpis[array] = args[array];
	}
            
	
            
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop assigns i, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
		
            
        /* >>> INNER LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant \valid_read(args + (0..i-1));
          loop invariant \forall integer k; 0 <= k < p ==> mpis[k] == mpis[k];
          loop assigns p, mpis[0..Array-1];
        */
        for (int p = 0; p < i; p++) {
			if (args[i] > args[p]
					&& mpis[i] < (mpis[p] * args[i])) {
				mpis[i] = mpis[p] * args[i];
			}
		}
            
	}
            
	int result = mpis[0];
	
            
    /* >>> LOOP INVARIANT FOR RESULT-FINDING LOOP <<< */
        
    /*@
      loop invariant \forall integer k; 0 <= k < Array ==> mpis[k] == mpis[k];
      loop assigns i, result;
    */
    for (int i = 1; i < Array; i++) {
		if (mpis[i] > result) {
			result = mpis[i];
		}
	}
            
	return result;
}
