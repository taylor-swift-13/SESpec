
/*@
  requires array > 0;
  requires \valid(data + (0 .. array - 1));
*/
int foo301(int * data, int data_len, int array) {

  int found = 0, top = array - 1;

  /*@
    loop invariant 0 <= found <= top;
    loop invariant top < array;
    loop invariant 0 <= found;
    loop variant top - found;
    loop assigns found, top;
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
