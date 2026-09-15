
        /*@ logic integer divisor_count_upto(integer n, integer d) =
      d < 2 ? 0 :
      divisor_count_upto(n, d - 1) + (((d <= n / d) && (n % d == 0)) ? 1 : 0); */
/*@ 
  assigns \nothing;

  behavior num_is_1:
    assumes num == 1;
    ensures \result == 1;

  behavior num_lt_1:
    assumes num < 1;
    ensures \result == 0;

  behavior num_gt_1:
    assumes num > 1;
    ensures \result >= 0;

  complete behaviors;
  disjoint behaviors;
*/
int foo317(int num) {
    int result = 0;

    if (num < 1)
        return 0;

    if (num == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop invariant size >= 2;
      loop assigns result, size;
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
