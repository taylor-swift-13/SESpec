
/*@
  assigns \nothing;
  ensures \result == fact(num) % 100;
*/
int foo394(int num) {

    int ret = 1;
        
    /*@
      loop invariant (loop <= \at(num,Pre)) ==> (\at(num,Pre) == num);
      loop invariant num == \at(num,Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
        
    int result = (int) (ret % 100);
    return result;
}
