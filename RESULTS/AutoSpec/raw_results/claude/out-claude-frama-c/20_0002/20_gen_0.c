/*@
requires n >= 0;
ensures n == 0 ==> \result == 1;
ensures n > 0 ==> \result == n * factorial(n-1);
assigns \nothing;

---

requires n >= 0;
ensures n == 0 ==> \result == 1;
ensures n > 0 ==> \result == 2 * power(n-1);
assigns \nothing;

---

requires n >= 0;
ensures \result == (n <= 2 ? 1 : power((n-2)/2) * factorial((n-2)/2));
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