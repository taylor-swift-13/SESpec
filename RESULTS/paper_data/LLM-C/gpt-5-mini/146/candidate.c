int isPowerOfFour(int n);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \old(n) <= 0 ==> \result == 0;
    ensures \result == 1 <==> (\old(n) > 0 && (\exists integer k; k >= 0 && \old(n) == (1 << (2*k))));
*/
int isPowerOfFour(int n) {

        if(n <= 0) {
            return 0;
        }
        /*@
            loop invariant n > 0;
            loop invariant \at(n,Pre) % n == 0;
            loop invariant (\exists integer k; k >= 0 && (\at(n,Pre) / n) == (1 << (2*k)));
            loop assigns n;
            loop variant n;
        */
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}
