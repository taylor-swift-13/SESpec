
/*@
  predicate is_alternating(int b, int n) = 
    \forall integer x; 0 <= x < n ==> ((x % 2 == 0) ==> (b == 1)) && ((x % 2 == 1) ==> (b == 0));
*/

/*@
  predicate alternating_updates(int i, int j, int n, int i_pre, int j_pre) =
    i == i_pre + (n / 2) + (n % 2) && j == j_pre + (n / 2);
*/

void foo156(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 1;

    /*@
      loop invariant (!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)));
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
