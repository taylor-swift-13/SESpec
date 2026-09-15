
/*@
  assigns \nothing;
*/
int foo319(int n, int y) {

  int ret = 1;
  int l = 1;
  if (n > y) {
    int g = n;
    n = y;
    y = g;
  }

  /*@
    loop assigns j, ret;
  */
  for (int j = 1; j <= n; j++) {
    if (n % j == 0 && y % j == 0) {
      ret = j;
    }
  }

  l = (n * y) / ret;
  return l;
}
