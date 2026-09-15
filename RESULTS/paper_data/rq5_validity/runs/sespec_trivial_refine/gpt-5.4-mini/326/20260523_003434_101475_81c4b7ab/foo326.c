
/*@ 
  logic integer fact(integer n) = 
    (n <= 1) ? 1 : n * fact(n - 1);
*/
/*@
  requires num >= 0;
  assigns \nothing;
  ensures 0 <= \result <= 9;
  ensures num <= 1 ==> \result == 1;
*/
int foo326(int num) {
  if (num <= 1) {
    return 1;
  }

  int first = 1;

  /*@
    loop assigns c, first;
    loop invariant 2 <= c <= num + 1;
    loop invariant first == fact(c - 1);
    loop invariant first >= 1;
    loop variant num - c + 1;
  */
  for (int c = 2; c <= num; c++) {
    first *= c;
  }

  int result = 0;

  /*@
    loop assigns first, result;
    loop invariant first >= 0;
    loop invariant 0 <= result <= 9;
    loop variant first;
  */
  while (first > 0) {
    result = first % 10;
    first /= 10;
  }

  return result;
}
