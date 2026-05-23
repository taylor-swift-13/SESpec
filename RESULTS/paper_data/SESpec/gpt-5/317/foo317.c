
/*@
  assigns \nothing;
  ensures num != 1 ==> \result >= 0;
*/
int foo317(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= size;
      loop invariant 0 <= result;
      loop invariant result <= size - 2;
      loop invariant \forall integer k; k < 2 ==> \true;
      loop invariant \forall integer k; 2 <= k < size ==> (k <= num / k ==> (num % k == 0 || num % k != 0));
      loop invariant \forall integer k; size <= k ==> \true;
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
