int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant 0 <= i <= length;
            loop invariant 0 <= count;
            loop invariant count <= (length * (length - 1)) / 2;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k + 1 <= j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 1);
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
