int minElementInArray(int * a, int a_len);

int minElementInArray(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}
