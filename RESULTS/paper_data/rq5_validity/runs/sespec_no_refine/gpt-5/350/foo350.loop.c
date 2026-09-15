
int foo350(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant total >= 0;
          loop invariant ret >= 0;
          loop invariant total == (num >> ret);
          loop invariant result == \sum(integer i = 0, ret - 1, ((i % 2 == 0) ? (1 << i) : 0));
          loop assigns result, ret, total;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return num ^ result;
}
