int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
}
