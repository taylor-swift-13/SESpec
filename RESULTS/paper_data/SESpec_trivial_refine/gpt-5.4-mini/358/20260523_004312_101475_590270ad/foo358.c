
/*@
  requires size > 0;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
  ensures \result <= size;
*/
int foo358(int size) {

    int average = 0;
    int total = 0;

    /*@
      loop invariant average == total * total;
      loop invariant total == index / 2;
      loop invariant 1 <= index <= size + 1;
      loop assigns average, total, index;
      loop variant size - index + 1;
    */
    for (int index = 1; index <= size; index++) {
        if (index % 2 != 0) {
            average += index;
            total++;
        }
    }

    return average / total;
}
