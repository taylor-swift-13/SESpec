int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        for (int i = 0; i < length - 1; i++) {
            /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant count >= 0;
            loop invariant 0 <= length == arr_len;
            loop invariant count == \numof{integer k,l; 0 <= k < i && k < l < length && arr[k] != arr[l]};
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
