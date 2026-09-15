int isPowerOfTwo(int n);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \old(n) <= 0 ==> \result == 0;
    ensures \old(n) > 0 ==> (\result == 1 <==> (\exists integer k; k >= 0 && \old(n) == 1 << k));
*/
int isPowerOfTwo(int n) {

        if(n <= 0) {
            return 0;
        }
        /*@
            loop invariant n >= 1;
            loop invariant \exists integer k; k >= 0 && \old(n) == n * (1 << k);
            loop assigns n;
            loop variant n;
        */
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
}
