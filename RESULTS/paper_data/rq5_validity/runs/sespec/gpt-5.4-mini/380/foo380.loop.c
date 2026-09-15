
/*@
  logic integer proper_divisor_sum(integer n, integer i) =
    i <= 1 ? 0 :
    proper_divisor_sum(n, i - 1) + ((n % (i - 1) == 0) ? (i - 1) : 0);
*/

int foo380(int number) {

        int sum = 0;
        
        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= sum;
          loop invariant number == \at(number,Pre);
          loop invariant sum <= (i - 1) * i / 2;
          loop invariant sum == proper_divisor_sum(number, i);
          loop invariant \forall integer j; 1 <= j < i && number % j == 0 ==> sum >= j;
          loop invariant \exists integer j; 0 <= j < i ==> (j == 0 || j < i);
          loop invariant (i <= \at(number,Pre) / 2) ==> (sum >= 0);
          loop invariant (i <= \at(number,Pre) / 2) ==> (sum == proper_divisor_sum(number, i));
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
