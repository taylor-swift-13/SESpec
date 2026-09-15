int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        for (int i = 0; i < length - 1; i++) {
            /*@
            loop invariant i <= length - 1;
            loop invariant count == \numof{integer k,l; 0 <= k < i && k < l < length && arr[k] != arr[l]};
            loop invariant count <= i * (length - i);
            loop invariant count <= i * (length - 1);
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (arr[p] != arr[q] ==> count >= 1);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k+1 <= l < length ==> (arr[k] != arr[l] ==> count >= 1);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k < l < length ==> (arr[k] != arr[l] ==> count >= 1);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k + 1 <= l < length ==> (arr[k] != arr[l] ==> count >= 1);
            loop invariant 0 <= length == arr_len;
            loop invariant 0 <= i;
            loop invariant 0 <= count;
            loop assigns j;
            loop assigns count;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
}
