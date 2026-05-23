/*@
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findOddPair(int * a, int a_len, int n);

 /*@
    requires a_len >= 0;
    requires \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop assigns i, count, j;
            loop variant length - i;
        */
        for (int i = 0; i < length; i++) {
            /*@
                loop invariant i + 1 <= j <= length;
                loop invariant 0 <= count;
                loop assigns j, count;
                loop variant length - j;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}
