
/*@
  requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;

  behavior singleton:
    assumes args_len == 1;
    assigns \nothing;
    ensures \result == 0;

  behavior nonsingleton:
    assumes args_len > 1;
    assigns \nothing;
    ensures \result >= 0;

  complete behaviors;
  disjoint behaviors;
*/
int foo278(int *args, int args_len) {
  if (args_len == 1) {
    return 0;
  }

  int ret = 0;
  int tmp = args[0];

  /*@
    loop invariant 1 <= j <= args_len;
    loop invariant ret >= 0;
    loop assigns j, ret, tmp;
    loop variant args_len - j;
  */
  for (int j = 1; j < args_len; j++) {
    if (args[j] > tmp) {
      ret = ret > tmp ? ret : tmp;
    } else {
      tmp = args[j];
    }
  }

  return ret;
}
