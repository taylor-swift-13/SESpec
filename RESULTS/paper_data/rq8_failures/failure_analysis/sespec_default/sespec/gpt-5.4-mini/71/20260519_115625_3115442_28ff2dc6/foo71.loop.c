
/*@
  logic integer count_mul5(integer x) = x / 5;
  logic integer count_mul4_not5(integer x) = x / 4 - x / 20;
  logic integer count_mul3_not2_not4_not5(integer x) = x / 3 - x / 6 - x / 12 + x / 60;
  logic integer count_mul2_not3_not4_not5(integer x) = x / 2 - x / 6 - x / 4 + x / 12;
  logic integer count_other(integer x) =
    x - count_mul5(x) - count_mul4_not5(x) - count_mul3_not2_not4_not5(x) - count_mul2_not3_not4_not5(x);
*/

void foo71(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant n == \at(n,Pre);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop assigns v3, v4, i, j, k, l;
    */
    while (l < n) {
       if ((l % 5) == 0){
         v3 = v3 + 1;
       }
       else if ((l % 4) == 0) {
         v4 = v4 + 1;
       }
       else if((l % 3) == 0){
         i = i + 1;
       }
       else if((l % 2) == 0){
         j = j + 1;
       }
       else{
         k = k + 1;
       }
       l = l + 1;
    }
}
