int foo59_c135(int x, int n);


int foo59_c135(int x, int n) {

        int res = 1;
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}