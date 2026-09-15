
        /*@
        logic integer bit_is_set(integer x, integer p) = ((x >> p) & 1);
        */
        
int foo354(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant even >= 0;
          loop invariant sum > 0 ==> sum <= num;
          loop assigns even, result, sum;
            */
            while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
            
		return (num | result);
}
