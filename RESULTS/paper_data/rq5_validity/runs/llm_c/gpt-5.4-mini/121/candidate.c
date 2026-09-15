/*@
    requires bits_len >= 1;
    requires \valid_read(bits + (0 .. bits_len - 1));
    requires \forall integer i; 0 <= i < bits_len ==> (bits[i] == 0 || bits[i] == 1);
    assigns \nothing;
    ensures \result == ( {
        int n = bits_len;
        int i = 0;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        i == n - 1;
    } );
*/
int isOneBitCharacter(int * bits, int bits_len);

 /*@
    requires bits_len >= 1;
    requires \valid_read(bits + (0 .. bits_len - 1));
    requires \forall integer i; 0 <= i < bits_len ==> (bits[i] == 0 || bits[i] == 1);
    assigns \nothing;
    ensures \result == ( {
        int n = bits_len;
        int i = 0;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        i == n - 1;
    } );
*/
int isOneBitCharacter(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant i < n - 1 ==> \valid_read(bits + i);
            loop invariant \forall integer k; 0 <= k < i ==> (bits[k] == 0 || bits[k] == 1);
            loop assigns i;
            loop variant (n - 1) - i;
        */
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}
