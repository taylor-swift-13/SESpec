int isCommonFactor(int a, int b, int factor);

int isCommonFactor(int a, int b, int factor) {

        if (a % factor != 0) {
            return 0;
        }
        if (b % factor != 0) {
            return 0;
        }
        return 1;
}
