int divisor(int num);

 /*@
     requires \true;
     assigns \nothing;
     ensures num <= 0 ==> \result == 0;
     ensures num > 0 ==> \result == (\sum integer k; 1 <= k <= num; (num % k == 0 ? 1 : 0));
     ensures 0 <= \result <= (num > 0 ? num : 0);
 */
int divisor(int num) {

		int div = 0;
		/*@
		    loop invariant c >= 1;
		    loop invariant (num < 1) || c <= num + 1;
		    loop invariant 0 <= div && div <= (num > 0 ? num : 0);
		    loop invariant div == (\sum integer k; 1 <= k < c && k <= num; (num % k == 0 ? 1 : 0));
		    loop assigns c, div;
		    loop variant num - c + 1;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}
