
/*@
  predicate parity(int x, int y) = (x + y) % 2 == 0;
*/

void foo162(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant (0 < (2 * \at(k,Pre))) ==> (n <= 2 * \at(k,Pre));
      loop invariant (0 < (2 * \at(k,Pre))) ==> (((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))) || ((b == 0) || (b == 1)));
      loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
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
