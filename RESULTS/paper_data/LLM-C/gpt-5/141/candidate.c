int numberOfCuts(int n);

/*@ 
  assigns \nothing;
  behavior n_is_one:
    assumes n == 1;
    ensures \result == 0;
  behavior n_even_not_one:
    assumes n != 1 && n % 2 == 0;
    ensures \result == n / 2;
  behavior n_odd_not_one:
    assumes n != 1 && n % 2 != 0;
    ensures \result == n;
  complete behaviors n_is_one, n_even_not_one, n_odd_not_one;
  disjoint behaviors n_is_one, n_even_not_one, n_odd_not_one;
@*/
int numberOfCuts(int n) {

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}
