int notCommonFactor(int a, int b, int factor);

int notCommonFactor(int a, int b, int factor) {

        if(a % factor != 0) {
            return 1;
        }
        if(b % factor != 0) {
            return 1;
        }
        return 0;
}
