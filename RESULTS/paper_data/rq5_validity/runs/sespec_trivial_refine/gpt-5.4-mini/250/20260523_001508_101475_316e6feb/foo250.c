
/*@
  requires 0 <= start <= stop < args_len;
  requires \valid_read(args + (start .. stop));
  requires \forall integer i, j; start <= i <= j <= stop ==> args[i] - i <= args[j] - j;
  assigns \nothing;
  ensures start <= \result <= stop + 1;
*/
int foo250(int * args, int args_len, int start, int stop) {

  int result = start;
  int total = stop;
  int mid;
  int i;

  /*@
    loop invariant start <= result <= stop + 1;
    loop invariant start - 1 <= total <= stop;
    loop invariant result <= total + 1;
    loop assigns result, total, mid, i;
    loop variant total - result + 1;
  */
  while (result <= total) {
    mid = (result + total) / 2;
    i = args[mid];

    if (i == mid) {
      result = mid + 1;
    } else if (i < mid) {
      result = mid + 1;
    } else {
      total = mid - 1;
    }
  }

  return result;
}
