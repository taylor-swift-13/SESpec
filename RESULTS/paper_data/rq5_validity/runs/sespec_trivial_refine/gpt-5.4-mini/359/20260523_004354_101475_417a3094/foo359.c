
/*@
  assigns \nothing;
  ensures \result >= 0;
*/
int foo359(int size) {
  int ret = 0;
  int total = 0;

  /*@
    loop invariant 1 <= c;
    loop invariant size < 0 || c <= size + 1;
    loop invariant 0 <= ret;
    loop invariant 0 <= total;
    loop assigns c, ret, total;
  */
  for (int c = 1; c <= size; c++) {
    if (c % 2 != 0) {
      ret += c;
      total++;
    }
  }

  if (total == 0) {
    return 0;
  }

  return ret / total;
}
