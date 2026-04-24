int isCommonMultiple(int a, int b, int m);

int isCommonMultiple(int a, int b, int m) {

        if(m % a != 0) {
            return 0;
        }
        if(m % b != 0) {
            return 0;
        }
        return 1;
}
