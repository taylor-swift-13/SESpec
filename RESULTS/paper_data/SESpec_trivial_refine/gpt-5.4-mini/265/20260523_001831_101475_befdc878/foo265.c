
/*@
  logic boolean is_odd(integer x) = x % 2 != 0;
*/

/*@
  requires 0 <= array;
  requires array <= ints_len;
  requires \valid_read(ints + (0 .. array - 1));
  assigns \nothing;
*/
int foo265(int *ints, int ints_len, int array) {
  int ret = 0;
  int start = 0;

  /*@
    loop invariant 0 <= index <= array;
    loop invariant 0 <= start <= index;
    loop assigns index, start, ret;
  */
  for (int index = 0; index < array; index++) {
    if (ints[index] % 2 != 0) {
      start++;
      if (start % 2 != 0) {
        ret = ints[index];
      }
    }
  }

  return ret;
}
