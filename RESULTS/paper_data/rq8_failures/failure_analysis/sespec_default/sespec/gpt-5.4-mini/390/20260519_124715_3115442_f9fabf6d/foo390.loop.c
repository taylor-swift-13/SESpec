
/*@ 
  logic integer fact(integer x) = x <= 0 ? 1 : x * fact(x - 1);
*/

int foo390(int n, int k) {

        int res = 1;
        int i = 1;
        
            
        /*@
          loop invariant (1 <= \at(k,Pre)) ==> (1 <= i <= k + 1);
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
