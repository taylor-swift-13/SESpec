/*@
    requires n >= 0;
    ensures \result == \pow(x, n);
    assigns \nothing;
*/
int power(int x, int n);

int power(int x, int n) {

        int res = 1;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant res == \pow(x, i);
            loop assigns i, res;
            loop variant n - i;
        */
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}
