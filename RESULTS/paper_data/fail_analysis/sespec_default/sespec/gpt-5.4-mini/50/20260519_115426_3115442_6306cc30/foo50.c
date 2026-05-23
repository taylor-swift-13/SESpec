
/*@ predicate alternating_state(int b, int n, int i, int j, int k0) =
      (b == 0 && n == 0 && k0 >= 0);
*/

void foo50(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n <= 2 * k);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (0 <= n);
      loop invariant (0 < (2 * \at(k,Pre))) ==> (b == 0 || b == 1);
      loop invariant k == \at(k,Pre);
      loop assigns n, b, i, j;
    */
    while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
       b = 0;
       i = i + 1;
      }
       else{
       b = 1;
       j = j + 1;
      }
      }
}
