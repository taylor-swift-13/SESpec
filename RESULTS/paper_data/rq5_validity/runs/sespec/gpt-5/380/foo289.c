
/*@ 
  logic integer partial_div_sum(integer number, integer cur) =
    cur > number / 2 ? 0 :
      (number % cur == 0 ? cur : 0) + partial_div_sum(number, cur + 1);
*/

/*@ 
  logic integer partial_div_prefix(integer number, integer cur) =
    cur <= 1 ? 0 :
      partial_div_prefix(number, cur - 1) + ((number % (cur - 1) == 0) ? (cur - 1) : 0);
*/
/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result == partial_div_prefix(number, number/2 + 1);
*/
int foo289(int number) {

        int sum = 0;
        
        /*@
          loop invariant 1 <= i;
          loop invariant i <= number / 2 + 1;
          loop invariant sum == partial_div_prefix(number, i);
          loop invariant number == \at(number,Pre);
          loop assigns i, sum;
          loop variant number/2 - i + 1;
        */
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
            
        return sum;
}
