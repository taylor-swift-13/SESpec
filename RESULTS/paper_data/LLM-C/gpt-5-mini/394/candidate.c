int lastTwoDigits(int num);

 /*@
     requires 0 <= num <= 12;
     assigns \nothing;
     ensures 0 <= \result < 100;
     ensures \exists integer m;
         m == (\product integer i; 1 <= i <= num; i) && \result == m % 100;
 */
int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		    loop invariant 1 <= loop <= num + 1;
		    loop invariant ret == (\product integer i; 1 <= i <= loop-1; i);
		    loop invariant ret >= 1;
		    loop assigns ret, loop;
		    loop variant num - loop + 1;
		*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
}
