
/*@
  logic integer power_of_two(integer exp) =
    exp <= 0 ? 1 : 2 * power_of_two(exp - 1);
*/

/*@
  logic integer bitwise_or_shift(integer num, integer even) =
    (even % 2 == 1) ? (num | power_of_two(even)) : num;
*/

/*@
  predicate even_bitwise_or(int even, int result, int num) =
    result == (\at(result,Pre) | power_of_two(even));
*/

int foo217(int num) {

    int even = 0;
    int result = 0;
    int sum = num;

    /*@
      loop invariant (\at(num,Pre) > 0) ==> (even_bitwise_or(even,result,num));
