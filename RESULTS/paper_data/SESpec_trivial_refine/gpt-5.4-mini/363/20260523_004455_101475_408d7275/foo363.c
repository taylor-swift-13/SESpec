
        /*@
  requires size >= 2;
  assigns \nothing;
  ensures size >= 2 ==> \result == size / 2 + 1;
  ensures size >= 2 ==> \result > 0;
  ensures size >= 2 ==> \result <= size;
*/
int foo363(int size) {
  int average = 0;
  int total = 0;

  /*@
    loop invariant 1 <= c <= size + 1;
    loop invariant total == (c - 1) / 2;
    loop invariant average == ((c - 1) / 2) * (((c - 1) / 2) + 1);
    loop invariant average >= 0;
    loop invariant total >= 0;
    loop assigns c, average, total;
  */
  for (int c = 1; c <= size; c++) {
    if (c % 2 == 0) {
      average += c;
      total++;
    }
  }

  return average / total;
}
