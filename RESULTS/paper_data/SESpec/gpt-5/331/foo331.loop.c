


int foo331(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant n < c ==> (index >= n + 1 && index <= c + 1);
          loop invariant n < c ==> (0 <= index - (n + 1) <= c - n);
          loop invariant index <= c + 1 ==> c - n < 5;
          loop invariant (index == n + 1) ==> (result == 1);
          loop invariant index > n + 1 && index <= c + 1 ==> ((result * 1) % 10) == result;
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
