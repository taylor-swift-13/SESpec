
/*@
  predicate UNUSED_PLACEHOLDER = \true;
*/

void foo307_c73(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (v1 + v2 + v3 + v4 + i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j && j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k && k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 && v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v3 && v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v2 && v2 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v1 && v1 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v1, v2, v3, v4, i, j, k, l;
    */
    while (l < n) {
       if((l % 7) == 0){
         v1 = v1 + 1;
       }
       else if((l % 6) == 0){
         v2 = v2 + 1;
       }
       else if ((l % 5) == 0){
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
