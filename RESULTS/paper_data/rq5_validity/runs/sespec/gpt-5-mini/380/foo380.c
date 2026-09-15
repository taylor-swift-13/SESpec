
/*@ 
  logic integer partial_sum(integer n, integer k) =
    k <= 0 ? 0 :
    partial_sum(n, k-1) + ((n % k) == 0 ? k : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures (\at(number,Pre) >= 1)
            ==> \result == partial_sum(\at(number,Pre), \at(number,Pre) / 2);
  ensures \at(number,Pre) == 0 ==> \result == 0;
*/
int foo380(int number) {

    int sum = 0;
    
    /*@
      loop invariant 1 <= i;
      loop invariant (\at(number,Pre) >= 0) ==> (i <= \at(number,Pre) / 2 + 1);
      loop invariant sum == partial_sum(\at(number,Pre), i-1);
      loop invariant number == \at(number,Pre);
      loop assigns i, sum;
    */
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
        
    return sum;
}
