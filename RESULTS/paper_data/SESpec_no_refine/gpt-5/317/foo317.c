
/*@
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result == pair_factor_count(num, num + 1);
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
