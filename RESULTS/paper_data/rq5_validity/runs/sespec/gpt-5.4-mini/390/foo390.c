
/*@
  logic integer falling_prod(integer n, integer k) =
    k <= 0 ? 1 : falling_prod(n, k - 1) * (n - k + 1);
*/

/*@
  assigns \nothing;
  
  ensures k <= 0 ==> \result == 1;
  ensures k > 0 ==> \result == falling_prod(n, k);
*/
int foo390(int n, int k) {

        int res = 1;
        int i = 1;
        
        /*@
          loop invariant 1 <= i;
          loop invariant (k < 1) || (i <= k + 1);
          loop invariant res == falling_prod(n, i - 1);
          loop invariant (i > 1) ==> res == falling_prod(n, i - 1);
          loop invariant (i == 1) ==> res == 1;
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);

          loop invariant (1 <= \at(k,Pre)) ==> (res == falling_prod(n, i - 1));
          loop invariant (1 <= \at(k,Pre)) ==> (1 <= i && i <= \at(k,Pre) + 1);
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
