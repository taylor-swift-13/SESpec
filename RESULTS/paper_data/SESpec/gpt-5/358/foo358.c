
/*@
  requires size >= 1;
  assigns \nothing;
*/
int foo358(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant size == \at(size,Pre);
      loop invariant average >= 0;
      loop invariant total >= 0;
      loop invariant total <= index - 1;
      loop invariant average >= total;
      loop invariant \forall integer k; 1 <= k < index ==> (total >= 0);
      loop invariant \forall integer k; 1 <= k < index && (k % 2 == 0) ==> (average == average);
      loop invariant \forall integer k; 1 <= k < index && (k % 2 != 0) ==> (average >= k);
      loop assigns index, average, total;
    */
    for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }

    return average / total;
}
