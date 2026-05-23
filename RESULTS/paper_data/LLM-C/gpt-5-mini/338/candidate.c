/*@
    predicate prime(integer p) = p >= 2 && (\forall integer d; 2 <= d && d <= p-1 ==> p % d != 0);
*/

/*@
    requires num >= 1;
    assigns \nothing;
    ensures \result >= 0;
    ensures \old(num) == 1 <==> \result == 0;
    ensures \old(num) >= 2 ==>
        prime(\result)
        && \old(num) % \result == 0
        && (\forall integer q; prime(q) && q > \result ==> \old(num) % q != 0);
*/
int maxPrimeFactors(int num) {

        int result = 0;
        /*@
            loop invariant 2 <= j;
            loop invariant result >= 0;
            loop invariant result == 0 || (result >= 2 && result < j);
            loop invariant \forall integer d; 2 <= d && d < j ==> num % d != 0;
            loop assigns j, num, result;
            loop variant num - j + 1;
        */
        for (int j = 2; j <= num; j++) {
            /*@
                loop invariant j >= 2;
                loop invariant num % j == 0;
                loop invariant result >= 0;
                loop assigns num, result;
                loop variant num;
            */
            while (num % j == 0) {
                result = j;
                num /= j;
            }
        }
        return result;
}
