/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= (a_len * (a_len - 1)) / 2;
    ensures \result == \sum integer p; 0 <= p < a_len; (
                        \sum integer q; p + 1 <= q < a_len;
                            ( ((a[p] ^ a[q]) % 2) == 1 ? 1 : 0 )
                    );
*/
int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
            loop invariant 0 <= i <= length;
            loop invariant count == \sum integer p; 0 <= p < i; (
                                        \sum integer q; p + 1 <= q < length;
                                            ( ((a[p] ^ a[q]) % 2) == 1 ? 1 : 0 )
                                    );
            loop assigns i, count;
            loop variant length - i;
        */
        for (int i = 0; i < length; i++) {
            /*@
                loop invariant i + 1 <= j <= length;
                loop invariant count == \sum integer p; 0 <= p < i; (
                                            \sum integer q; p + 1 <= q < length;
                                                ( ((a[p] ^ a[q]) % 2) == 1 ? 1 : 0 )
                                        )
                                      + (\sum integer q; i + 1 <= q < j;
                                            ( ((a[i] ^ a[q]) % 2) == 1 ? 1 : 0 ));
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
