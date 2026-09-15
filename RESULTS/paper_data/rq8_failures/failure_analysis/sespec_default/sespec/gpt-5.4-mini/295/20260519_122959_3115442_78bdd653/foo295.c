
/*@
  requires num >= 1;
  assigns \nothing;
*/
int foo295(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= l;
          loop invariant result[0] == 2;
          loop invariant result[1] == 1;
          loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2];
          loop assigns l, result[0..num];
            */
            for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[num];
}
