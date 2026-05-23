
int foo338(int num) {

		int result = 0;
		
            /*@
          loop invariant \true;
          loop invariant j >= 2;
          loop assigns j, result, num;
            */
            for (int j = 2; j <= num; j++) {
			
            /*@
          loop invariant \true;
          loop invariant j >= 2;
          loop assigns j, result, num;
            */
            while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
            
		return result;
}
