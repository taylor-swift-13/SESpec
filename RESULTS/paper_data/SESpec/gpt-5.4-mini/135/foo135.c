int foo135(int x, int n);


/*@ logic integer ipow(integer x, integer n) =
      n <= 0 ? 1 : x * ipow(x, n - 1); */
/*@ 
  requires n >= 0;
  assigns \nothing;
  ensures \result == ipow(x, n);
  ensures n <= 0 ==> \result == 1;
  ensures n > 0 ==> \result == x * ipow(x, n - 1);
  ensures x == 1 ==> \result == ipow(x, n);
  ensures x == 0 && n > 0 ==> \result == 0;
*/
int foo135(int x, int n) {

        int res = 1;
        /*@ loop invariant 0 <= i <= n;
            loop invariant res == ipow(x, i);
            loop assigns i, res;
            loop variant n - i;
        */
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}