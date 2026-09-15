int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)};
            loop assigns i;
            loop assigns count;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}
