
/*@ logic integer fact(integer n) =
      (n <= 1) ? 1 : n * fact(n - 1);
*/
/*@ 
  requires 0 <= num <= 10;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result < 100;

  ensures num <= 1 ==> \result == 1;
  ensures num == 2 ==> \result == 2;
  ensures num == 3 ==> \result == 6;
  ensures num == 4 ==> \result == 24;
  ensures num == 5 ==> \result == 20;
  ensures num == 6 ==> \result == 20;
  ensures num == 7 ==> \result == 40;
  ensures num == 8 ==> \result == 20;
  ensures num == 9 ==> \result == 80;
  ensures num >= 10 ==> \result == 0;
*/
int foo394(int num) {
    int ret = 1;

    /*@
      loop invariant 1 <= loop;
      loop invariant loop <= num + 1;
      loop invariant ret == fact(loop - 1);
      loop assigns ret, loop;
      loop variant num - loop + 1;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }

    int result = (int)(ret % 100);
    return result;
}
