
/*@
  assigns \nothing;
  ensures \result == 0 ==>
            (\forall integer j; 1 <= j <= n ==> !is_sol(j, x, y));
  ensures \result != 0 ==>
            1 <= \result <= n
            && is_sol(\result, x, y)
            && (\forall integer j; \result < j <= n ==> !is_sol(j, x, y));
*/
int foo382(int n, int x, int y) {

        int max = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == 0
                        || (1 <= max <= i - 1 && is_sol(max, x, y));
          loop assigns i, max;
            */
            for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
            
        return max;
}
