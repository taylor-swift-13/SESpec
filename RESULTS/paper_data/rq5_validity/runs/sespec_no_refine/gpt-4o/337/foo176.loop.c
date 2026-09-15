
/*@
  // No additional predicates or logic functions are required for this program.
*/

int foo176(int num) {
    int ret = 0;

    /*@
      loop invariant 2 <= j <= \at(num,Pre) + 1;
      loop invariant ret == 0 || (num % ret != 0 && ret <= \at(num,Pre));
      loop invariant \forall integer k; 2 <= k < j ==> \at(num,Pre) % k != 0;
      loop assigns j, ret, num;
    */
    for (int j = 2; j <= num; j++) {
        /*@
          loop invariant 2 <= j <= num + 1;
          loop invariant ret == 0 || (num % ret != 0 && ret <= num);
          loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
          loop assigns j, ret, num;
        */
        while (num % j == 0) {
            ret = j;
            num /= j;
        }
    }

    return ret;
}
