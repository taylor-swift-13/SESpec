
        /*@
        
        */
        
int foo353(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result >= 0;
          loop invariant max >= 0;
          loop invariant result == 0 || sum <= num;
          loop assigns result, max, sum;
            */
            while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | max);
}
