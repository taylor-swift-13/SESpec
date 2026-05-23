
        /*@
        logic integer dummy(integer x) = x;
        */
        
int foo373(int number) {

		int div = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= div;
          loop invariant 1 <= index;
          loop invariant div <= index - 1;
          loop assigns div, index;
            */
            for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
            
		return div;
}
