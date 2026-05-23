
/*@ 
  logic integer product_from_to(integer a, integer b) =
    a > b ? 1 : a * product_from_to(a+1, b);
*/

/*@
  requires \true;
  ensures \true;
*/
int foo390(int n, int k) {

        int res = 1;
        int i = 1;
        
            
        /*@
          loop invariant 1 <= \at(k,Pre) ==> 1 <= i <= \at(k,Pre) + 1;
          loop invariant 1 <= \at(k,Pre) ==> res == product_from_to(n - (i - 1) + 1, n);
          loop invariant 1 <= \at(k,Pre) ==> res == product_from_to(n - i + 2, n);
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
