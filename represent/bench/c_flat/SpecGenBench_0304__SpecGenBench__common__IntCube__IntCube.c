int cubeOf(int x);

int cubeOf(int x) {

        int neg = 0;
        if(x < 0) {
            neg = 1;
            x = -x;
        }
        int res = 0;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < x; j++) {
                for(int k = 0; k < x; k++) {
                    res = res + 1;
                }
            }
        }
        return (neg ? -res : res);
}
