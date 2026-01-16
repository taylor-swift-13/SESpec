/*@
requires n >= 0;
ensures \result == (n == 0 ? 1 : n * factorial(n - 1));
assigns \nothing;
*/
int factorial(int n) {

  if (n == 0) {
    return 1;
  }
  return n * factorial(n-1);
}

int power(int n) {
  if (n == 0) {
    return 1;
  }
  return 2 * power(n-1);
}

int pdt(int n) {
  int prod = 1;
  int i = 2;

  while(i < n) {
    prod = power(i/2)*factorial(i/2);
    i = i+2;
  }
  return prod;
}

int doo1() {
    int p = pdt(10);
    // @ assert p == 1;
}