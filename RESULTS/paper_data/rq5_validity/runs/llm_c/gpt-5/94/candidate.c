int canWinNim(int n);

/*@
  requires \true;
  assigns \nothing;

  behavior multiple_of_4:
    assumes n % 4 == 0;
    ensures \result == 0;

  behavior not_multiple_of_4:
    assumes n % 4 != 0;
    ensures \result == 1;

  ensures 0 <= \result <= 1;

  complete behaviors multiple_of_4, not_multiple_of_4;
  disjoint behaviors multiple_of_4, not_multiple_of_4;
*/
int canWinNim(int n) {
        return n % 4 != 0;
}
