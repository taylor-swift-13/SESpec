/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \old(num) <= 1 ==> \result == 0;
    ensures \old(num) > 1 ==>
        ( \result >= 2
        && \old(num) % \result == 0
        && (\forall integer d; 1 < d < \result ==> \result % d != 0)
        && (\forall integer p; p > 1 && \old(num) % p == 0 && (\forall integer d; 1 < d < p ==> p % d != 0) ==> p <= \result)
        );
*/
int maxPrimeFactors(int num) {

		int result = 0;
		/*@ ghost int N = num; */

		/*@
		    loop invariant 2 <= c <= N+1;
		    loop invariant 0 <= result && result <= N;
		    loop invariant N >= 0;
		    loop invariant num >= 0 && num <= N;
		    loop invariant N % num == 0;
		    loop assigns c, num, result;
		    loop variant N - c + 1;
		*/
		for (int c = 2; c <= num; c++) {
			/*@
			    loop invariant num >= 1;
			    loop invariant N % num == 0;
			    loop invariant 0 <= result && result <= N;
			    loop invariant 2 <= c && c <= N;
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
