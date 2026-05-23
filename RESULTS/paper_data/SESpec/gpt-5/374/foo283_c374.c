
/*@ 
  logic integer count_divisors_prefix(integer number, integer k) =
    k <= 0 ? 0 :
    count_divisors_prefix(number, k - 1) + ((k != 0 && number % k == 0) ? 1 : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures 0 <= \result;
*/
int foo283_c374(int number) {

    int div = 0;
        
    /*@
      loop invariant 1 <= c;
      loop invariant number == \at(number,Pre);
      loop invariant 0 <= div <= c - 1;
      loop invariant div == count_divisors_prefix(number, c - 1);
      loop assigns c, div;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }
        
    return div;
}
