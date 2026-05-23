/*@
    requires \true;
    ensures \result == 1 <==> n > 0 && (\exists integer k; n == (1 << k));
    ensures \result == 0 <==> !(n > 0 && (\exists integer k; n == (1 << k)));
    assigns \nothing;
*/
int isPowerOfTwo(int n) {

    if (n <= 0) {
        return 0;
    }
    /*@
        loop invariant n > 0;
        loop invariant \forall integer k; n == (1 << k) ==> n % 2 == 0;
        loop assigns n;
        loop variant n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
