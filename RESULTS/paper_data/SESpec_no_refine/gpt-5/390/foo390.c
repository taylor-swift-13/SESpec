
/*@
  assigns \nothing;
  ensures (k <= 0) ==> (\result == 1);
  ensures (k >= 1) ==> (\result == prod_desc(n, k));
  ensures n == \old(n) && k == \old(k);
*/
int foo390(int n, int k) {

        int res = 1;
        int i = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (1 <= \at(k,Pre)) ==> (0 <= i-1 <= \at(k,Pre));
          loop invariant (1 <= \at(k,Pre)) ==> (res == prod_desc(\at(n,Pre), i - 1));
          loop invariant (1 <= \at(k,Pre)) ==> (1 <= i <= \at(k,Pre) + 1);
          loop invariant (!(1 <= \at(k,Pre))) ==> ((i == 1)&&(res == 1)&&(k == \at(k,Pre))&&(n == \at(n,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns res, i;
            */
            while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
            
        return res;
}
