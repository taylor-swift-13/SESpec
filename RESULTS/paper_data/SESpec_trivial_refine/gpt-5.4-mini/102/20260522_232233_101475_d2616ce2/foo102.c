
/*@
  requires num >= 0;
  assigns \nothing;
  ensures \old(num) >= 10 ==> \result >= 0;
  ensures \old(num) >= 10 ==> \result < 10;
  ensures \old(num) >= 10 ==> \result != \old(num);
*/
int foo102(int num) {

  /*@
    loop invariant num >= 0;
    loop assigns num;
    loop variant num;
  */
  while (num >= 10) {
    int sum = 0;

    /*@
      loop invariant sum >= 0;
      loop invariant num >= 0;
      loop assigns num, sum;
      loop variant num;
    */
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }

    num = sum;
  }

  return num;
}
