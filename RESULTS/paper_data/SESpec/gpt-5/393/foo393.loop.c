


int foo393(int num) {

    int ret = 1;
        
    /*@
      loop invariant ret >= 1;
      loop invariant (loop == 1) ==> (ret == 1);
      loop invariant (loop > 1) ==> (ret >= loop - 1);
      loop invariant \forall integer k; 1 <= k < loop ==> ret >= k;
      loop invariant ((loop <= \at(num,Pre)) ==> (ret * (loop) >= ret));
      loop invariant ((loop <= \at(num,Pre)) ==> (ret * loop >= loop));
      loop invariant ((loop > \at(num,Pre)) ==> (ret >= \at(num,Pre)));
      loop invariant ((loop > \at(num,Pre)) ==> (ret >= 1));
      loop invariant ((loop > \at(num,Pre)) ==> (ret % 1 == 0));
      loop invariant ((loop <= \at(num,Pre)) ==> (ret == 1 || ret >= loop - 1));
      loop invariant (loop <= \at(num,Pre)) ==> (ret >= 1);
      loop invariant num == \at(num,Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
        
    int remainder = (int) (ret % 100);
    return remainder;
}
