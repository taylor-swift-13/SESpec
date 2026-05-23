
/*@ 
  assigns \nothing;
  
*/
int foo372(int num) {

		int div = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c;
          loop assigns c, div;
            */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
            
		return div;
}
