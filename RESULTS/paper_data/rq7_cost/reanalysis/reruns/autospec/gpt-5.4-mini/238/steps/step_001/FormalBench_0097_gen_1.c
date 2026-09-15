int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop invariant count == \sum(0, i-1, \lambda integer ii; \sum(ii+1, length-1, \lambda integer jj; (((a[ii] ^ a[jj]) % 2) == 1 ? 1 : 0)));
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
