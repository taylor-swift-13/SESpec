
        /*@
        logic integer sum(integer n) = n <= 0 ? 0 : sum(n - 1) + n;
        */
        
/*@
        logic integer sumcube(integer n) = n <= 0 ? 0 : sumcube(n - 1) + n * n * n;
        */
        

int foo330(int diff) {

		int result = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == 0;
          loop invariant j >= 1;
          loop invariant result == sumcube(j - 1);
          loop assigns result, j;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant j >= 1;
          loop invariant max == sum(j - 1);
          loop assigns max, j;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
