
/*@ 
  predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
  requires \true;
*/
void foo295_c67(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (i >= 0 && j >= 0 && k >= 0 && i % 3 == 0 && j % 3 == 0 && k % 3 == 0 && j + k == i);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= n + 2);
      loop invariant (!(0 < \at(n,Pre))) ==> ((j == 0)&&(k == 0)&&(i == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, k;
    */
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
         j = j + 3;
       else
         k = k + 3;
    }
}
