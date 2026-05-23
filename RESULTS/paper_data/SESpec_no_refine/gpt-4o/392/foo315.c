
/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == factorial(num) % 100;
*/
int foo315(int num) {

    int ret = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant 1 <= number && number <= num + 1;
      loop invariant ret == factorial(number - 1);
      loop assigns number, ret;
      loop variant num - number;
    */
    for (int number = 1; number <= num; number++) {
        ret *= number;
    }

    int result = (int) (ret % 100);
    return result;
}
