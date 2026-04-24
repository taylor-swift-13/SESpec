int isCommonFactor(int a, int b, int factor);

int isCommonFactor(int a, int b, int factor) {

        return a % factor == 0 && b % factor == 0;
}
