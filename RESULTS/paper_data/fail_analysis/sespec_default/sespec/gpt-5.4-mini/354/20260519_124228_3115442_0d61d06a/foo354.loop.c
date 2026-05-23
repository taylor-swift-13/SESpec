
int foo354(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		
        /*@
          loop invariant 0 <= even;
          loop invariant sum == \at(num,Pre) >> even;
          loop invariant num == \at(num,Pre);
          loop assigns result, sum, even;
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
