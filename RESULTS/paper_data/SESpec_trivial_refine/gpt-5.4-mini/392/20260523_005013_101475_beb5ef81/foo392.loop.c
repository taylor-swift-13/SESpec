
        /*@
        logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1);
        */
        
int foo392(int num) {

		int ret = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns ret, number;
          loop invariant number >= 1;
          loop invariant ret == fact(number - 1);
            */
            for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
