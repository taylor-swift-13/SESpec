int foo128(int s);

int foo128(int s) {

        int foo128 = 0;

        for (int l = 1; l <= s; l++) {
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo128) {
                    foo128 = volume;
                }
            }
        }
        return foo128;
}
