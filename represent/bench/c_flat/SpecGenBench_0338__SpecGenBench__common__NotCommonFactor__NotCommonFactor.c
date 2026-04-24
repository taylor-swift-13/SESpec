int notCommonFactor(int a, int b, int factor);

int notCommonFactor(int a, int b, int factor) {

        return a % factor != 0 || b % factor != 0;
}
