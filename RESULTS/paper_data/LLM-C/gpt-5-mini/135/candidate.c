int power(int x, int n);

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == (\product integer i; 0 <= i < n; x);
*/
int power(int x, int n) {

        int res = 1;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant res == (\product integer j; 0 <= j < i; x);
            loop assigns i, res;
            loop variant n - i;
        */
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}
