int frequency(int * a, int a_len, int x);

int frequency(int * a, int a_len, int x) {

        int count = 0;
        for (int i = 0; i < a_len; i++) {
            if (a[i] == x) {
                count++;
            }
        }
        return count;
}
