/*@
    requires num >= 0;
    assigns \nothing;
    ensures \old(num) <= 1 ==> \result == 0;
    ensures \old(num) > 1 ==>
        (\result > 1
         && \old(num) % \result == 0
         && (\forall integer t; 2 <= t && t <= \result - 1 ==> \result % t != 0)
         && (\forall integer p; 2 <= p && p <= \old(num) && \old(num) % p == 0
             && (\forall integer t; 2 <= t && t <= p - 1 ==> p % t != 0) ==> p <= \result));
*/
int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		/*@
		    loop invariant j >= 2;
		    loop invariant ret >= 0;
		    /* If some factor < j was found, ret records a factor found so far */
		    loop invariant (ret > 0) ==> (\old(num) % ret == 0);
		    loop assigns j, num, ret;
		    /* Variant is non-negative and strictly decreases at each iteration:
		       V = num + (\old(num) + 1 - j) * (\old(num) + 1)
		       When the inner while divides num the first term decreases;
		       when j increments the second term decreases by (\old(num)+1). */
		    loop variant num + (\old(num) + 1 - j) * (\old(num) + 1);
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			    loop invariant j >= 2;
			    loop invariant ret >= 0;
			    loop invariant (ret > 0) ==> (\old(num) % ret == 0);
			    loop assigns num, ret;
			    loop variant num;
			*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
