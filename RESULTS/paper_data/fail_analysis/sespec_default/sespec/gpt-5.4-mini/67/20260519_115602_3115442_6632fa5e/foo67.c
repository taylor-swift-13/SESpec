
/*@
  logic integer mod3(integer x) = x - 3 * (x / 3);
*/

void foo67(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (i >= 0);
      loop invariant (0 < \at(n,Pre)) ==> (k >= 0);
      loop invariant (0 < \at(n,Pre)) ==> (j >= 0);
      loop invariant (0 < \at(n,Pre)) ==> ((i == 3 * (i / 3)) && (j == 3 * (j / 3)) && (k == 3 * (k / 3)));
      loop invariant (0 < \at(n,Pre)) ==> (((i / 3) + (j / 3) + (k / 3)) * 3 == i + j + k);
      loop invariant (0 < \at(n,Pre)) ==> (i == j + k);
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
