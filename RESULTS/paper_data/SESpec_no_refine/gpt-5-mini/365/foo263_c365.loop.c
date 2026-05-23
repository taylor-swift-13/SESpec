
/*@ 
  predicate PreN(integer n) = \true;
*/

/*@
  requires \true;
*/
int foo263_c365(int n) {

    int sum = 0;
    int count = 0;
    
    /*@
      loop invariant n == \at(n,Pre);
      loop assigns i, sum, count;
    */
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
            count++;
        }
    }
        
    return sum / count;
}
