
/*@
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  requires num == \at(num, Pre);
  assigns \nothing;
  ensures \result == (factorial(num) % 100);
*/
int foo315(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= number <= num + 1;
      loop invariant ret == factorial(number - 1);
      loop invariant num == \at(num, Pre);
      loop assigns number, ret;
    */
    for (int number = 1; number <= num; number++) {
        ret *= number;
    }

    int result = (int) (ret % 100);
    return result;
}
