/*@ 
  requires n >= 1;
  assigns \nothing;

  behavior one:
    assumes n == 1;
    ensures \result == 0;

  behavior even:
    assumes n != 1 && n % 2 == 0;
    ensures \result == n / 2;

  behavior odd:
    assumes n != 1 && n % 2 != 0;
    ensures \result == n;

  complete behaviors one, even, odd;
  disjoint behaviors one, even, odd;

  ensures 0 <= \result;
  ensures \result <= n;
*/
int numberOfCuts(int n);

int numberOfCuts(int n) {

        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
}
