int countPairs(int * arr, int arr_len, int n);

/* 3. FUNC CONTRACT */
int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        /* 2. LOOP INVARIANT */
        for (int i = 0; i < length - 1; i++) {
            /* 1. LOOP INVARIANT */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
}
