
/*@
  logic integer sum_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? n + sum_evens(n-1) : sum_evens(n-1));
*/

/*@
  logic integer count_evens(integer n) =
    n <= 0 ? 0 : (n % 2 == 0 ? 1 + count_evens(n-1) : count_evens(n-1));
*/

/*@
  requires count_evens(size) > 0;
  assigns \nothing;
*/
int foo361(int size) {

    int average = 0;
    int total = 0;
		
    /*@
      loop invariant 0 <= total;
      loop invariant total <= j - 1;
      loop invariant 0 <= average;
      loop invariant average == sum_evens(j-1);
      loop invariant total == count_evens(j-1);
      loop invariant (j == \at(size,Pre) + 1) ==>
        ( average == sum_evens(\at(size,Pre)) && total == count_evens(\at(size,Pre)) );
      loop invariant size == \at(size,Pre);
      loop assigns j, average, total;
    */
    for (int j = 1; j <= size; j++) {
        if (j % 2 == 0) {
            average += j;
            total++;
        }
    }
            
    return average / total;
}
