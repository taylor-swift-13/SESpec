int findDivisor(int x, int y);

int findDivisor(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}
