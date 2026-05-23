
/*@
logic integer fallfact(integer n, integer k) = \product(integer j; 1 <= j <= k; n - j + 1);
*/

int foo390(int n, int k) {

        int res = 1;
        int i = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 1;
          loop invariant res == \product(integer j; 1 <= j < i; n - j + 1);
          loop assigns res, i;
            */
            while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
            
        return res;
}
