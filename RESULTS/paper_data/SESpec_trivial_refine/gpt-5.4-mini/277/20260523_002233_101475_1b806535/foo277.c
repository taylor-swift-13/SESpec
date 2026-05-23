
        /*@
  requires arg_len > 0;
  requires \valid_read(arg + (0 .. arg_len - 1));
  assigns \nothing;

  ensures \result == 0 || \result == (arg[0] > 0 ? arg[0] : 0);
*/
int foo277(int *arg, int arg_len)
{
  if (arg_len == 1) {
    return 0;
  }

  int all_noninc = 1;
  int all_strictinc = 1;

  /*@
    loop assigns j, all_noninc, all_strictinc;
    loop variant arg_len - j;
  */
  for (int j = 1; j < arg_len; j++) {
    if (arg[j] > arg[j - 1]) {
      all_noninc = 0;
    } else {
      all_strictinc = 0;
    }
  }

  if (all_noninc) {
    return 0;
  }

  if (all_strictinc) {
    return arg[0] > 0 ? arg[0] : 0;
  }

  return 0;
}
