/*@ 
    requires n >= 0;
    assigns \nothing;
    ensures \result == 1 || n > 0;
*/
int power(int x, int n);

 /*@ 
    requires n >= 0;
    assigns \nothing;
    ensures \result == 1 || n > 0;
*/
int power(int x, int n) {

        int res = 1;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant res == 1 || i > 0;
            loop assigns i, res;
            loop variant n - i;
        */
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}
