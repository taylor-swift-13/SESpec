
int foo211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= j;
          loop invariant 0 <= count;
          loop assigns i, j, count;
        */
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
