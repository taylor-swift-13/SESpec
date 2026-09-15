/*@
    requires \valid(bits + (0..bits_len-1));
    requires bits_len > 0;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> bits[bits_len-1] == 0;
    ensures \result == 0 ==> bits[bits_len-1] != 0;
    assigns \nothing;
*/
int isOneBitCharacter(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        /*@
            loop invariant 0 <= i <= n - 1;
            loop invariant \forall integer k; 0 <= k < i ==> k + bits[k] + 1 <= i;
            loop assigns i;
            loop variant n - 1 - i;
        */
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}
