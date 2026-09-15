int countPairs(int * arr, int arr_len, int n);

int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        for (int i = 0; i < length - 1; i++) {
            /*@
            loop invariant 0 <= i <= length - 1;
            loop invariant 0 <= count <= length * (length - 1) / 2;
            loop invariant count == \sum(integer x = 0, length - 2) \sum(integer y = x + 1, length - 1) ((arr[x] != arr[y]) ? 1 : 0);
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
