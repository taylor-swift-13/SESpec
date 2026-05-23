
/*@
  logic integer digit_count(integer n) = 
    (n <= 0) ? 0 : 1 + digit_count(n / 10);
*/

/*@
  requires ret == 0;
  requires number == \at(number, Pre);
*/
int foo324(int number) {

    int ret = 0;

    /*@
      loop invariant (\at(number,Pre) > 0) ==> (number >= 0);
      loop invariant (\at(number,Pre) > 0) ==> (ret + digit_count(number) == digit_count(\at(number,Pre)));
      loop invariant (!(\at(number,Pre) > 0)) ==> ((ret == 0)&&(number == \at(number,Pre)));
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }

    return ret;
}
