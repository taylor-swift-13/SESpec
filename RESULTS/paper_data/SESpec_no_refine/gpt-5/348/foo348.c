
/*@
  assigns \nothing;
  ensures (\result == -1) <==> (\forall integer i; l <= i <= r ==> not_divisible_count(l, i, a) != n);
  ensures \result != -1 ==> (l <= \result <= r && not_divisible_count(l, \result, a) == n &&
                             (\forall integer j; l <= j < \result ==> not_divisible_count(l, j, a) != n));
*/
int foo348(int a, int n, int l, int r) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer k; l <= k < i ==> 0 <= not_divisible_count(l, k, a);
          loop invariant count == (i > l ? not_divisible_count(l, i-1, a) : 0);
          loop assigns i, count;
            */
            for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
            
        return -1;
}
