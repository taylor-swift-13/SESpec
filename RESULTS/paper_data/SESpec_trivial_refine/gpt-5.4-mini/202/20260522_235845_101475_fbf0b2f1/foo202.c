
        /*@
        */

/*@
  requires ints_len >= array;
  requires array >= 1;
  requires \valid_read(ints + (0 .. array - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= array - 1;
  ensures array == 1 ==> \result == 0;
*/
int foo202(int *ints, int ints_len, int array) {
  int find = 0;
  int min = 0;
  int offset = 1;

  /*@
    loop invariant 0 <= find <= min;
    loop invariant 0 <= min <= array;
    loop invariant 1 <= offset <= array;
    loop assigns find, min, offset;
    loop variant array - offset + array - min;
  */
  while (min < array && offset < array) {
    if (ints[min] == ints[offset]) {
      min++;
      offset++;
      find++;
    } else if (ints[min] > ints[offset]) {
      min++;
    } else {
      offset++;
    }
  }

  return find;
}
