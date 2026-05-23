
/*@
  logic integer division(integer a, integer b) = (b != 0) ? a / b : 0;
*/

/*@
  logic integer modulo(integer a, integer b) = (b != 0) ? a % b : 0;
*/

/*@
  logic integer is_factor(integer num, integer factor) = (factor > 0) && (modulo(num, factor) == 0);
*/

/*@
  logic integer count_factors(integer num, integer limit) =
    (limit <= 1) ? 0 :
    (is_factor(num, limit) ? 1 : 0) + count_factors(num, limit - 1);
*/

/*@
  logic integer total_factors(integer num) = count_factors(num, division(num, 2));
*/

/*@
  requires num > 0;
  assigns \nothing;
  ensures \result == total_factors(num);
*/
int foo133(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= size <= num / size + 1;
      loop invariant result == count_factors(num, size - 1);
      loop invariant \forall integer k; 2 <= k < size ==> is_factor(num, k) ==> (num / k >= k);
      loop assigns size, result;
      loop variant num / size - size;
    */
    for (int size = 2; size <= num / size; size++) {
        if (num % size == 0) {
            result++;
            if (num / size == size) {
                break;
            }
        }
    }

    return result;
}
