
/*@ 
  assigns \nothing;
  
  ensures (!(1 <= \old(k))) ==> (\result == 1);
  ensures n == \old(n);
  ensures k == \old(k);
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
