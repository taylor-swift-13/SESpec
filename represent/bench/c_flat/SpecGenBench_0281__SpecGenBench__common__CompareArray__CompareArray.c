int arrcmp(int * a, int a_len, int * b, int b_len);

int arrcmp(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
