int isOneBitCharacter(int * bits, int bits_len);

/*@
    requires bits_len >= 0;
    requires bits_len == 0 || \valid_read(bits + (0..bits_len-1));
    requires \forall integer j; 0 <= j < bits_len ==> bits[j] == 0 || bits[j] == 1;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isOneBitCharacter(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant n == bits_len;
            loop invariant \forall integer j; 0 <= j < n ==> bits[j] == 0 || bits[j] == 1;
            loop assigns i;
            loop variant n - i;
        */
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}
