
/*@
  requires args_len > 0;
  requires \valid_read(args + (0 .. args_len - 1));
  requires 0 <= start <= stop < args_len;
  requires \forall integer i, j; start <= i <= j <= stop ==> args[i] + (j - i) <= args[j];
  assigns \nothing;
  ensures start <= \result <= stop + 1;
*/
int foo249(int *args, int args_len, int start, int stop)
{
  int found = start;
  int num = stop;
  int mid;
  int i;

  /*@
    loop invariant start <= found <= stop + 1;
    loop invariant start - 1 <= num <= stop;
    loop invariant found <= num + 1;
    loop assigns found, num, mid, i;
    loop variant num - found + 1;
  */
  while (found <= num) {
    mid = (found + num) / 2;
    i = args[mid];

    if (i <= mid) {
      found = mid + 1;
    } else {
      num = mid - 1;
    }
  }

  return found;
}
