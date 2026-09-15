/*@
    requires \true;
    assigns \nothing;
    ensures \result == 1 <==> (\exists integer k; k >= 0 && \pow(4, k) == n);
    ensures \result == 0 <==> !(\exists integer k; k >= 0 && \pow(4, k) == n);
*/
int isPowerOfFour(int n) {

        if(n <= 0) {
            return 0;
        }
        /*@
        loop invariant n > 0;
        loop invariant \exists integer k; k >= 0 && n == \old(n) / \pow(4, k);
        loop assigns n;
        loop variant n;
        */
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}
