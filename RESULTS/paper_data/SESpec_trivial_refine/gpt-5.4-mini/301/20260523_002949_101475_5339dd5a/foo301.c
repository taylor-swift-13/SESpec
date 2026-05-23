
/*@
  requires array > 0;
  requires \valid(data + (0 .. array - 1));
  assigns \nothing;
  ensures 0 <= \result < array;
*/
int foo301(int * data, int data_len, int array) {

  int found = 0, top = array - 1;

  /*@
    loop invariant 0 <= found <= top < array;
    loop assigns found, top;
    loop variant top - found;
  */
  while (found < top) {
    int i = found + (top - found) / 2;
    if (data[i] < data[i + 1]) {
      found = i + 1;
    } else {
      top = i;
    }
  }

  return found;
}
