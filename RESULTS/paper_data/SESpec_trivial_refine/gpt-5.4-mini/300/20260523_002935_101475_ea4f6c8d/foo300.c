
/*@
predicate in_bounds(int i, int n) = 0 <= i < n;
*/

/*@
  requires Array >= 0;
  requires Array > 0 ==> \valid_read(array + (0 .. Array - 1));
  requires Array > 1 ==> (\forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1]);
  assigns \nothing;
  ensures Array <= 0 ==> \result == 0;
  ensures Array > 0 ==> 0 <= \result < Array;
  ensures Array > 0 ==> \valid_read(array + (\result .. \result));
  ensures Array > 0 ==> (\result == 0 || array[\result] >= array[\result - 1]);
  ensures Array > 0 ==> (\result == Array - 1 || array[\result] >= array[\result + 1]);
*/
int foo300(int *array, int array_len, int Array)
{
  if (Array <= 0) {
    return 0;
  }

  int found = 0, top = Array - 1;

  /*@
    loop invariant 0 <= found;
    loop invariant found <= top;
    loop invariant top < Array;
    loop invariant found == 0 || array[found] >= array[found - 1];
    loop invariant top == Array - 1 || array[top] >= array[top + 1];
    loop assigns found, top;
    loop variant top - found;
  */
  while (found < top) {
    int i = found + (top - found) / 2;
    if (array[i] < array[i + 1]) {
      found = i + 1;
    } else {
      top = i;
    }
  }

  return found;
}
