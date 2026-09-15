
/*@
  requires \true;
  assigns \nothing;
  ensures number <= 0 ==> \result == 0;
*/
int foo398(int number) {

    int ret = 0;

    /*@
      loop invariant number >= 0 || number == \at(number, Pre);
      loop invariant ret >= 0;
      loop invariant (\at(number, Pre) > 0) ==> (ret >= 0);
      loop invariant (\at(number, Pre) > 0) ==> (number >= 0);
      loop invariant (!(\at(number, Pre) > 0)) ==> ((ret == 0) && (number == \at(number, Pre)));
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }

    return ret;
}
