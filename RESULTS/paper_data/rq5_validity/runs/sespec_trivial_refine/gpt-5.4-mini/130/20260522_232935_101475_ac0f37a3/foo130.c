
/*@
  requires array_len >= 0;
  requires array_len == 0 || \valid_read(array + (0 .. array_len - 1));
  assigns \nothing;
  ensures \result == -1 ==> \forall integer i; 0 <= i < array_len ==> array[i] != search;
  ensures \result != -1 ==> 0 <= \result < array_len;
  ensures \result != -1 ==> array[\result] == search;
  ensures \result == -1 || array[\result] == search;
  ensures \result != -1 ==> \exists integer i; 0 <= i < array_len && array[i] == search;
*/
int foo130(int search, int array[], int array_len) {

  int location = -1;
  int c;

  /*@
    loop invariant 0 <= c <= array_len;
    loop invariant location == -1 || (0 <= location < c && array[location] == search);
    loop invariant location == -1 ==> \forall integer i; 0 <= i < c ==> array[i] != search;
    loop invariant location != -1 ==> \exists integer i; 0 <= i < c && array[i] == search;
    loop assigns c, location;
    loop variant array_len - c;
  */
  for (c = 0; c < array_len; c++) {
    if (location == -1 && array[c] == search) {
      location = c;
      break;
    }
  }

  return location;
}
