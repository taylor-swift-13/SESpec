int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        for (int i = 0; i < length - 1; i++) {
            /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant 0 <= count;
            loop invariant \forall integer p, q; 0 <= p < i && p < q < length ==> (arr[p] != arr[q] ==> count >= 1);
            loop assigns i;
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
