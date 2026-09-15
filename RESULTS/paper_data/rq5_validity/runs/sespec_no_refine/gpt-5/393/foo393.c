
/*@
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result <= 99;
*/
int foo393(int num) {

    int ret = 1;
        
    /*@
      loop invariant num == \at(num,Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
            
    int remainder = (int) (ret % 100);
    return remainder;
}
