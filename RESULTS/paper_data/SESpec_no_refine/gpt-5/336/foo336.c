
/*@
  requires \true;
  assigns \nothing;
*/
int foo336(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns num, result;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
