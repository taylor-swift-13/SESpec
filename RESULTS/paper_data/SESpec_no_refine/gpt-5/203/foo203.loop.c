
/*@
  // no additional logic functions or predicates needed
*/

int foo203(int * array, int array_len, int Array) {

    int find = 0;
    int offset = 0;
    int max = 1;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant Array == \at(Array,Pre);
      loop invariant array_len == \at(array_len,Pre);
      loop invariant array == \at(array,Pre);

      loop invariant 0 <= offset <= Array;
      loop invariant 0 <= max <= Array;
      loop invariant 0 <= find;

      loop invariant (offset == 0 && max == 1 && find == 0) ||
                      (max >= 1 && offset <= max);

      loop assigns offset, max, find;
    */
    while (offset < Array && max < Array) {
        if (array[offset] == array[max]) {
            offset++;
            max++;
            find++;
        } else if (array[offset] > array[max]) {
            offset++;
        } else {
            max++;
        }
    }

    return find;
}
