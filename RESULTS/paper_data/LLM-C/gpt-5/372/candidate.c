int divisor(int num);

/*@ 
  requires num >= 1;
  assigns \nothing;
  ensures \result == \numof integer k; 1 <= k <= num && num % k == 0;
  ensures 1 <= \result <= num;
*/
int divisor(int num) {

		int div = 0;
		/*@
		  loop invariant 1 <= c <= num + 1;
		  loop invariant 0 <= div <= c - 1;
		  loop invariant div == \numof integer k; 1 <= k < c && num % k == 0;
		  loop assigns div, c;
		  loop variant num - c + 1;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}
