
/*@
  // No additional predicates or logic functions are required for this program.
*/

int foo176(int num) {

    int ret = 0;
    
    /*@
      loop invariant 2 <= j <= \at(num,Pre) + 1;
      loop invariant (j <= \at(num,Pre)) ==> (num >= 0);
      loop invariant (j <= \at(num,Pre)) ==> 
          (((ret == 0) && (num == \at(num,Pre))) || 
           ((ret > 0) && (\at(num,Pre) % ret == 0) && (ret <= \at(num,Pre))));
      loop invariant (!(j <= \at(num,Pre))) ==> ((ret == 0) && (num == \at(num,Pre)));
      loop assigns j, ret, num;
    */
    for (int j = 2; j <= num; j++) {
        
        /*@
          loop invariant 2 <= j <= num + 1;
          loop invariant ret == 0 || (num % ret == 0 && ret <= num);
          loop invariant num >= 0;
          loop assigns j, ret, num;
        */
        while (num % j == 0) {
            ret = j;
            num /= j;
        }
        
    }
            
    return ret;
}
