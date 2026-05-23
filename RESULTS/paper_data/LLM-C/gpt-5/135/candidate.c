/*@ 
  logic integer ipow(integer x, integer n) =
    n <= 0 ? (n == 0 ? 1 : 0) : x * ipow(x, n - 1);
*/

int power(int x, int n);

/*@
  requires 0 <= n;
  assigns \nothing;
  ensures \result == ipow(x, n);
*/
int power(int x, int n) {

        int res = 1;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant res == ipow(x, i);
          loop assigns i, res;
          loop variant n - i;
        */
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}
