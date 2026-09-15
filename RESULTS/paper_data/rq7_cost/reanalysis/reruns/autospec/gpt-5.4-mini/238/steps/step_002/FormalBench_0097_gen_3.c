int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
        loop invariant 0 <= count <= length * (length - 1) / 2;
        loop invariant 0 <= i <= length;
        loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)};
        loop assigns i;
        loop assigns count;
        */
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant i <= length;
            loop invariant count == \sum(0, i-1, \lambda integer ii; \sum(ii+1, length-1, \lambda integer jj; (((a[ii] ^ a[jj]) % 2) == 1 ? 1 : 0)));
            loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)};
            loop invariant count <= length * (length - 1) / 2;
            loop invariant count <= i * length;
            loop invariant count <= i * (length - 1);
            loop invariant count <= (length * (length - 1)) / 2;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k+1 <= l < length ==> ((a[k] ^ a[l]) % 2 == 1) ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k < j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 0);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k < j < length ==> (((a[k] ^ a[j]) % 2) == 1 ==> count >= 1);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k + 1 <= j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 1);
            loop invariant 0 <= i;
            loop invariant 0 <= count;
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
