int getPosition(int * a, int a_len, int n, int m);

int getPosition(int * a, int a_len, int n, int m) {

        int pos = 0;
        for (int i = 0; i < a_len; i++) {
            if (a[i] == n) {
                pos = i;
                break;
            }
        }
        return pos + m;
}
