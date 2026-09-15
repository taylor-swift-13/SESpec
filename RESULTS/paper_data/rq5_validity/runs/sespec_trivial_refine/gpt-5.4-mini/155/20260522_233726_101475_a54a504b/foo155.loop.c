
/*@
predicate args_readable{L}(int *args, integer n) =
  \valid_read(args + (0 .. n-1));
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
  requires 0 < Array;
  requires \valid_read(args + (0 .. Array-1));
*/


int foo155(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		
            /*@
          loop invariant 0 <= array <= Array;
          loop assigns array, mpis[0 .. Array-1];
            */
            for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
            
            /*@
          loop invariant 1 <= i <= Array;
          loop assigns i, mpis[1 .. Array-1];
            */
            for (int i = 1; i < Array; i++) {
			
            /*@
          loop invariant 0 <= k <= i;
          loop assigns k, mpis[i];
            */
            for (int k = 0; k < i; k++) {
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
            
		}
            
		int num = mpis[0];
		
            /*@
          loop invariant 1 <= i <= Array;
          loop invariant \forall integer j; 0 <= j < i ==> num >= mpis[j];
          loop assigns i, num;
            */
            for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
            
		return num;
}
