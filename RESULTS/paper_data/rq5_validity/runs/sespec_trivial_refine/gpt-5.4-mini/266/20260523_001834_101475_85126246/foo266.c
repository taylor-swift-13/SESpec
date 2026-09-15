
/*@
predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
  requires 0 <= Array <= array_len;
  requires Array == 0 || \valid_read(array + (0 .. Array - 1));
  assigns \nothing;
  ensures \result == 0 || is_odd(\result);
*/
int foo266(int *array, int array_len, int Array) {
  int ret = 0;
  int start = 0;

  /*@
    loop invariant 0 <= index <= Array;
    loop invariant 0 <= start <= index;
    loop invariant ret == 0 || ret % 2 != 0;
    loop assigns index, start, ret;
    loop variant Array - index;
  */
  for (int index = 0; index < Array; index++) {
    if (array[index] % 2 != 0) {
      start++;
      if (start % 2 != 0) {
        /*@ assert array[index] % 2 != 0; */
        ret = array[index];
      }
    }
  }

  return ret;
}
