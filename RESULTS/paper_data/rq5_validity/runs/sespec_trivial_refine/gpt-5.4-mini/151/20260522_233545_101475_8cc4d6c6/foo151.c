
/*@
  requires 0 <= number;
  assigns \nothing;
  ensures 1 <= p && p <= (number + 1) / 2 ==> \result == 2 * p - 1;
  ensures p <= 0 || p > (number + 1) / 2 ==> \result == 0;
  ensures \result == 0 || \result == 2 * p - 1;
  ensures \result >= 0;
  ensures \result <= number;
*/
int foo151(int number, int p) {
  if (1 <= p && p <= (number + 1) / 2) {
    return 2 * p - 1;
  }
  return 0;
}
