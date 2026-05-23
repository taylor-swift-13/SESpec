/*@
    requires num >= 2;
    assigns \nothing;
    ensures \result >= 2;
    ensures \result <= num;
    ensures \forall integer d; 2 <= d <= num && num % d == 0 ==> d <= \result;
*/
int maxPrimeFactors(int num);

 /*@
    requires num >= 2;
    assigns \nothing;
    ensures \result >= 2;
    ensures \result <= \old(num);
    ensures \forall integer d; 2 <= d <= \old(num) && \old(num) % d == 0 ==> d <= \result;
*/
int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		    loop invariant 2 <= c <= num + 1;
		    loop invariant result == 0 || result >= 2;
		    loop invariant result == 0 || result <= \at(num,LoopEntry);
		    loop invariant \forall integer d; 2 <= d < c && \at(num,LoopEntry) % d == 0 ==> d <= result;
		    loop assigns c, result, num;
		    loop variant num - c;
		*/
		for (int c = 2; c <= num; c++) {
			/*@
			    loop invariant num >= 1;
			    loop invariant result == c;
			    loop invariant num > 0;
			    loop assigns num, result;
			    loop variant num;
			*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
