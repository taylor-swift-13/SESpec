int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop invariant count <= i * length;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k < j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 0);
            loop assigns count;
            loop assigns i;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}
