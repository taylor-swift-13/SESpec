
        /*@
        */
        
int foo317(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result == (\sum integer k; 2 <= k < size && num % k == 0; 1);
          loop invariant size >= 2;
          loop assigns result, size;
            */
            for (int size = 2; size <= num / size; size++) {
			if (num % size == 0) {
				result++;
				if (num / size == size) {
					break;
				}
			}
		}
            
		return result;
}
