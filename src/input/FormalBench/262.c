int foo262(int * tuplex, int tuplex_len, int value);

int foo262(int * tuplex, int tuplex_len, int value) {

        int count = 0;
        for (int i = 0; i < tuplex_len; i++) {
            if (tuplex[i] == value) {
                count++;
            }
        }
        return count;
}
