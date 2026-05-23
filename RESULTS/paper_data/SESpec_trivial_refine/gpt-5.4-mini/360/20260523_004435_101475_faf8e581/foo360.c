
/*@
  assigns \nothing;
  ensures size >= 1 ==> \result == (size + 1) / 2;
  ensures size >= 1 ==> \result >= 1;
  ensures size <= 0 ==> \result == 0;
*/
int foo360(int size) {
  if (size <= 0) return 0;

  int average = 0;
  int total = 0;

  /*@
    loop invariant 1 <= c <= size + 1;
    loop invariant total == c / 2;
    loop invariant average == total * total;
    loop assigns c, average, total;
    loop variant size + 1 - c;
  */
  for (int c = 1; c <= size; c++) {
    if (c % 2 != 0) {
      average += c;
      total++;
    }
  }

  return average / total;
}
