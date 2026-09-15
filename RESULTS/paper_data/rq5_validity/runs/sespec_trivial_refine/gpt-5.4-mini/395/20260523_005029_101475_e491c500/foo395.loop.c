
/*@
logic integer pow4(integer x) = x * x * x * x;
*/

int foo395(int p) {

		int odd = 0;
		
        /*@
          loop invariant odd % 2 == 0;
          loop invariant c >= 1;
          loop assigns c, odd;
        */
        for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
            
		return odd;
}
