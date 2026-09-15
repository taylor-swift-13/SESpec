int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        for (int i = 0; i < length - 1; i++) {
            /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant 0 <= count;
            loop invariant count <= i * (length - i);
            loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k < l < length ==> (arr[k] != arr[l] ==> count >= 1);
            loop assigns count;
            loop assigns i;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
}
