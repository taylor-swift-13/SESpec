



int foo329(int diff) {

		int ret = 0;
		int max = 0;
		
            /*@ 
              loop invariant ret >= 0;
              loop invariant max == 0;
              loop invariant j >= 1;
              loop assigns ret, j;
            */
            for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \true;
              loop invariant max == (j - 1) * j / 2;
              loop invariant j >= 1;
              loop assigns max, j;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return ret - max;
}
