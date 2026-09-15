
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/
/*@ 
  logic integer copied_at(int* args, int* mpis, integer i) =
    i <= 0 ? 0 : copied_at(args, mpis, i - 1) + (mpis[i - 1] == args[i - 1] ? 1 : 0);
*/
/*@
        predicate all_copied(int* args, int* mpis, integer i) =
          \forall integer j; 0 <= j < i ==> mpis[j] == args[j];
        */
/*@
        predicate same_prefix(int* args, int* mpis, integer i) =
          \forall integer j; 0 <= j < i ==> mpis[j] == args[j];
        */

        

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/



int foo155(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
        int mpis_len = Array;
		
        /*@
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
			
            /*@
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
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num >= mpis[0];
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
