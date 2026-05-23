
const char * foo281(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result >= 0;
          loop invariant index >= 1;
          loop invariant result <= index - 1;
          loop assigns result, index;
            */
            for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
