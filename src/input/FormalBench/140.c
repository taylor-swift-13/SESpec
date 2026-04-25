int foo140(int x, int y);

int foo140(int x, int y) {

        int gcd = 1;
        int foo140 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        foo140 = (x * y) / gcd;
        return foo140;
}
