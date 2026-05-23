
/*@
  logic integer sum(integer n) =
    n <= 0 ? 0 : sum(n - 1) + n;

  logic integer sumcube(integer n) =
    n <= 0 ? 0 : sumcube(n - 1) + n * n * n;
*/

/*@
  assigns \nothing;

  behavior nonpositive:
    assumes diff <= 0;

  behavior positive:
    assumes diff > 0;
    ensures \result == sumcube(diff) - sum(diff);

  complete behaviors;
  disjoint behaviors;
*/
int foo330(int diff) {

  int result = 0;
  int max = 0;

  /*@
    loop invariant 0 <= result;
    loop invariant result == sumcube(j - 1);
    loop invariant 1 <= j;
    loop invariant diff <= 0 || j <= diff + 1;
    loop assigns result, j;
    loop variant diff - j + 1;
  */
  for (int j = 1; j <= diff; j++) {
    result += j * j * j;
  }

  /*@
    loop invariant 0 <= max;
    loop invariant max == sum(j - 1);
    loop invariant 1 <= j;
    loop invariant diff <= 0 || j <= diff + 1;
    loop assigns max, j;
    loop variant diff - j + 1;
  */
  for (int j = 1; j <= diff; j++) {
    max += j;
  }

  return result - max;
}
