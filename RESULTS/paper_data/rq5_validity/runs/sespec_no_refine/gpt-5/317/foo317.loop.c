
/*@
  logic integer pair_factor_count(integer n, integer s) =
    s <= 2 ? 0 :
    (pair_factor_count(n, s - 1) +
     ((2 <= s - 1 && (s - 1) <= n / (s - 1) && n % (s - 1) == 0 && n / (s - 1) != (s - 1)) ? 1 : 0));
*/

int foo317(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= size;
      loop invariant result >= 0;
      loop invariant \forall integer d; 2 <= d < size ==> (d > num / d) || (num % d != 0) || (num / d != d);
      loop invariant result == pair_factor_count(num, size);
      loop assigns size, result;
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
