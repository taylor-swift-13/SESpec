int foo59_c135(int x, int n);


/*@ logic integer powi(integer x, integer n) =
      n <= 0 ? 1 : x * powi(x, n - 1); */
/*@ 
  requires n >= 0;
  // No overflow during computation: all intermediate results fit in int
  requires x == 0 ==> n <= 1; // avoid 0^n creating undefined intermediate? (still fine but keeps bounds consistent)
  requires x != 0 ==> 
            (\abs(x) == 1 || 
             // For |x| >= 2, bound the final magnitude to fit in int
             (n == 0) || 
             (n == 1 && \abs(x) <= 2147483647) || 
             (n >= 2 && powi(\abs(x), n) <= 2147483647));
  assigns \nothing;
*/
int foo59_c135(int x, int n) {
        int res = 1;
        for(int i = 0; i < n; i++)
            res = res * x;
        return res;
}