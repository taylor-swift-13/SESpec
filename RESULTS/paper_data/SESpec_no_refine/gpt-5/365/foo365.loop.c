
/*@
  logic integer odd_count_upto(integer k) =
    k <= 0 ? 0 : odd_count_upto(k - 1) + (k % 2 != 0 ? 1 : 0);

  logic integer odd_sum_upto(integer k) =
    k <= 0 ? 0 : odd_sum_upto(k - 1) + (k % 2 != 0 ? k : 0);
*/

int foo365(int n) {

    int sum = 0;
    int count = 0;
        
    /*@
      loop invariant 1 <= i;
      loop invariant sum == odd_sum_upto(i - 1);
      loop invariant count == odd_count_upto(i - 1);
      loop invariant (i <= \at(n,Pre)) ==> (sum == odd_sum_upto(i - 1)) ;
      loop invariant (i <= \at(n,Pre)) ==> (count == odd_count_upto(i - 1)) ;
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
