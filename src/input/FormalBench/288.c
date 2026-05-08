int foo288(int l, int r);

int foo288(int l, int r) {

        int sum = 0;
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}
