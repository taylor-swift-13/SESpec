
        /*@
        requires c >= 1;
        */
        

int foo287(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p <= c + 1;
          loop invariant j[0] == 0 && j[1] == 1;
          loop assigns p, j[2..c];
            */
            for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
            
		return j[c];
}
