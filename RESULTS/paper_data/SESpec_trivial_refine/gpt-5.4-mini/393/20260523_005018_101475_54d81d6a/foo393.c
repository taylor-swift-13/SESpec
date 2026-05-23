
/*@ logic integer fact(integer n) =
      n <= 0 ? 1 : n * fact(n - 1);
*/
/*@
  requires num <= 12;
  assigns \nothing;
  ensures num <= 0 ==> \result == 1;
  ensures num > 0 ==> \result == fact(num) % 100;
  ensures 0 <= \result < 100;
*/
int foo393(int num) {

  if (num <= 0) {
    return 1;
  }

  int ret = 1;

  /*@
    loop invariant 1 <= loop <= num + 1;
    loop invariant ret == fact(loop - 1);
    loop invariant ret >= 1;
    loop assigns ret, loop;
    loop variant num - loop + 1;
  */
  for (int loop = 1; loop <= num; loop++) {
    ret *= loop;
  }

  return (int)(ret % 100);
}
