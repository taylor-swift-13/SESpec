/*@
    requires number >= 0;
    ensures \result >= 0;
    ensures number == 0 ==> \result == 0;
    assigns \nothing;
*/
int countDigit(int number);

 /*@ 
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures number == 0 ==> \result == 0;
    ensures number > 0 ==> \result > 0;
*/
int countDigit(int number) {

		int ret = 0;
		/*@
		    loop invariant number >= 0;
		    loop invariant ret >= 0;
		    loop invariant (\old(number) == 0) ==> (ret == 0);
		    loop assigns number, ret;
		    loop variant number;
		*/
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}
