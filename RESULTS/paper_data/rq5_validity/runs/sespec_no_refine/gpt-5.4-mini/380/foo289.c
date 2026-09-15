
/*@ 
  assigns \nothing;
  ensures \result == 0 ? number < 1 : \result == sum_to(number / 2) - sum_to(0);
*/
int foo289(int number) {
    int sum = 0;

    /*@
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
