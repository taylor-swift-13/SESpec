
/*@
  requires array_len >= 0;
  requires \valid(array + (0 .. array_len-1));
  ensures -1 <= \result < array_len;
  assigns \nothing;
*/
int foo130(int search, int array[], int array_len) {

    int location = -1;
    int c;

    /*@
      loop invariant 0 <= c <= array_len;
      loop invariant -1 <= location < array_len;
      loop invariant (location != -1) ==> (0 <= location < c && array[location] == search);
      loop invariant (location == -1) ==> (\forall integer k; 0 <= k < c ==> array[k] != search);
      loop assigns c, location;
    */
    for (c = 0; c < array_len; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }

    if (c == array_len) {
        location = -1;
    }
    return location;
}
