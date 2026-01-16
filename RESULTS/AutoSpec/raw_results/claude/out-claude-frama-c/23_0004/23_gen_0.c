

/*@
requires n >= 0;
ensures \result == (n == 0 ? 1 : 2 * power(n - 1));
assigns \nothing;
*/
int power(int n) {
  if (n == 0) {
    return 1;
  }
  return 2 * power(n-1);
}

int fun(int n) {
    double y = 0;
    double i = 0;

    while(i <= n) {
        y = y + power(i);
        i = i + 1;
    }
    return y;
}

int doo4() {
    int res = fun(4);
    //@assert res == 7;
}