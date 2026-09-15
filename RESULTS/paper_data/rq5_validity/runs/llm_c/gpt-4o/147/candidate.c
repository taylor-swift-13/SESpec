/*@
    requires n > 0;
    ensures \result == 1 <==> (\exists integer k; k >= 0 && \pow(3, k) == n);
    ensures \result == 0 <==> !(\exists integer k; k >= 0 && \pow(3, k) == n);
    assigns \nothing;
*/
int isPowerOfThree(int n) {

        int temp = n;
        /*@
        loop invariant temp > 0;
        loop invariant n > 0;
        loop invariant \exists integer k; k >= 0 && temp == n / \pow(3, k);
        loop assigns temp;
        loop variant temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
