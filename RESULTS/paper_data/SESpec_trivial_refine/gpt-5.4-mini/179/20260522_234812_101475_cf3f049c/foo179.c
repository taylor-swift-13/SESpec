
/*@
  requires array_len > 0;
  requires array != \null;
  requires 0 < count <= array_len;
  requires \valid_read(array + (0 .. array_len - 1));
  assigns \nothing;
  ensures 1 <= \result <= count;
  ensures count == 1 ==> \result == 1;
  ensures count > 1 && array[0] < array[count - 1] ==> \result == 1;
*/
int foo179(int *array, int array_len, int count)
{
  /*@
    assert count > 0;
  */

  if (count > 1 && array[0] < array[count - 1]) {
    return 1;
  }

  int r = 0, top = count - 1;

  /*@
    loop invariant 0 <= r <= top < count;
    loop invariant top < array_len;
    loop assigns r, top;
    loop variant top - r;
  */
  while (r < top) {
    if (array[r] < array[top]) {
      return r + 1;
    }
    int end = (r + top) / 2;
    if (array[end] > array[r]) {
      r = end;
    } else {
      top = end;
    }
  }

  return r + 1;
}
