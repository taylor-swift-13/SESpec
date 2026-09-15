/*@
    requires \valid(a+(0..a_len-1));
    requires a_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
            loop invariant 0 <= i <= length;
            loop invariant count >= 0;
            loop assigns i, count;
        */
        for (int i = 0; i < length; i++) {
            /*@
                loop invariant i + 1 <= j <= length;
                loop invariant count >= 0;
                loop assigns j, count;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}
