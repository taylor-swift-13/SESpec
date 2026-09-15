/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result == (({ 
        int ret = 1;
        int loop;
        for (loop = 1; loop <= num; loop++) ret *= loop;
        ret % 100;
    }));
*/
int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		    loop invariant 1 <= loop <= num + 1;
		    loop invariant ret > 0;
		    loop assigns loop, ret;
		    loop variant num - loop + 1;
		*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
}
