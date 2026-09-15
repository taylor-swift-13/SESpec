int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
        loop invariant length == a_len;
        loop invariant i <= length;
        loop invariant i <= count;
        loop invariant i < count;
        loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)};
        loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)};
        loop invariant count <= length * (length - 1) / 2;
        loop invariant count <= i * length;
        loop invariant count <= i * (length - 1);
        loop invariant count <= (length * (length - 1)) / 2;
        loop invariant count < i * length;
        loop invariant count % 1 == 0;
        loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)} == count;
        loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)} <= count;
        loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)} == count;
        loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)} <= count;
        loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[a_len-1]) % 2) == 1)} <= count;
        loop invariant \forall integer q; i <= q < length ==> q < length;
        loop invariant \forall integer q; i <= q < length ==> count <= length * length;
        loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> ((a[p] ^ a[q]) % 2 == 1) ==> count >= 0;
        loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
        loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count <= length * length;
        loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> ((a[p] ^ a[q]) % 2 == 1) ==> count >= 0;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> ((a[p] ^ a[q]) % 2 == 1) ==> count <= length * (length - 1) / 2;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 1;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count <= length * (length - 1) / 2;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count <= (length * (length - 1)) / 2;
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count <= length * (length - 1) / 2);
        loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count <= (length * (length - 1)) / 2);
        loop invariant \forall integer k; i <= k < length ==> count <= (length * (length - 1)) / 2;
        loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k+1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1) ==> count >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1) ==> count >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1 ==> count >= 1);
        loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1 ==> count >= 0);
        loop invariant \exists integer p, q; 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;
        */
        for (int i = 0; i < length; i++) {
            /*@
            loop invariant i <= j <= length;
            loop invariant j - i >= 1;
            loop invariant 0 <= count <= (length * (length - 1)) / 2;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1 || ((a[k] ^ a[l]) % 2) == 0);
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (a[p] ^ a[q]) % 2 >= 0;
            loop invariant count == 0 || count > 0;
            loop invariant j <= length;
            loop invariant i <= length;
            loop invariant i <= j;
            loop invariant i < length;
            loop invariant i < length || count <= (i * (length - 1)) + length;
            loop invariant i < j;
            loop invariant i < j || j == i + 1;
            loop invariant i + 1 <= j;
            loop invariant count == \sum(0, i-1, \lambda integer ii; \sum(ii+1, length-1, \lambda integer jj; (((a[ii] ^ a[jj]) % 2) == 1 ? 1 : 0)));
            loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)};
            loop invariant count == \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)};
            loop invariant count <= length * (length - 1) / 2;
            loop invariant count <= i * length;
            loop invariant count <= i * (length - 1);
            loop invariant count <= (length * (length - 1)) / 2;
            loop invariant count <= (j - i) * (length - 1);
            loop invariant count <= (i + 1) * length;
            loop invariant count <= (i * (length - 1)) + length;
            loop invariant count < (i * (length - 1)) + length;
            loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)} == count;
            loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && ((a[p] ^ a[q]) % 2 == 1)} <= count;
            loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)} == count;
            loop invariant \numof{integer p, q | 0 <= p < i && p < q < length && (((a[p] ^ a[q]) % 2) == 1)} <= count;
            loop invariant \numof{integer p, q | 0 <= p < i && p < q < j && (((a[p] ^ a[q]) % 2) == 1)} == count;
            loop invariant \forall integer q; j <= q < length ==> q < length;
            loop invariant \forall integer q; i < q < length ==> count <= length * length;
            loop invariant \forall integer q; i + 1 <= q < length ==> q < length;
            loop invariant \forall integer q; i + 1 <= q < length ==> j <= q || q < length;
            loop invariant \forall integer q; i + 1 <= q < length ==> j <= q || q < j;
            loop invariant \forall integer q; i + 1 <= q < length ==> j <= length;
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> ((a[p] ^ a[q]) % 2 == 1) ==> count >= 0;
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; p < q < j ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
            loop invariant \forall integer p; 0 <= p < i ==> \forall integer q; i + 1 <= q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
            loop invariant \forall integer p, q; i <= p < length && p < q < length ==> count >= 0;
            loop invariant \forall integer p, q; 0 <= p < i ==> p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> count >= 0;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> ((a[p] ^ a[q]) % 2 == 1) ==> count >= 0;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count >= 0;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1) ==> count <= length * (length - 1) / 2;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (((a[p] ^ a[q]) % 2) == 1 ==> count >= 0);
            loop invariant \forall integer l; i + 1 <= l < length ==> (count <= length * (length - 1)) / 2;
            loop invariant \forall integer k; i + 1 <= k < j ==> (((a[i] ^ a[k]) % 2) == 1) ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k+1 <= l < length ==> ((a[k] ^ a[l]) % 2 == 1) ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> ((a[k] ^ a[l]) % 2 == 1) ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1) ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1) ==> count <= length * (length - 1) / 2;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1 ==> count >= 0);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (((a[k] ^ a[l]) % 2) == 1 ==> count <= length * (length - 1) / 2);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < j ==> count >= 0;
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k < j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 0);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k < j < length ==> (((a[k] ^ a[j]) % 2) == 1 ==> count >= 1);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer j; k + 1 <= j < length ==> ((a[k] ^ a[j]) % 2 == 1 ==> count >= 1);
            loop invariant 0 <= j;
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
