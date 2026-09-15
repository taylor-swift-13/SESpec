
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  ensures \result == 0 || \result >= 2;
  ensures \result == 0 || \result <= \old(num);
  ensures \result == 0 || \old(num) % \result == 0;
  ensures \result == 0 || \forall integer k; 2 <= k <= \old(num) ==> (k > \result || \old(num) % k != 0);
  assigns \nothing;
*/
int foo177(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns j, result, num;
            */
            for (int j = 2; j <= num; j++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop assigns result, num;
            */
            while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
            
		return result;
}