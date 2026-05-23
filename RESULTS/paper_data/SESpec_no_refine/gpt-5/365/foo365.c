
/*@
  assigns \nothing;
  ensures n == \old(n);
  ensures odd_count_upto(n) > 0 ==> \result == odd_sum_upto(n) / odd_count_upto(n);
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
