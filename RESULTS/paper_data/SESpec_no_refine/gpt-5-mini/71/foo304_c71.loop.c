
/*@ 
  predicate counts_partition(unsigned int l, unsigned int v3, unsigned int v4,
                             unsigned int i, unsigned int j, unsigned int k, unsigned int nPre) =
    l <= nPre &&
    v3 + v4 + i + j + k == l &&
    v3 <= l && v4 <= l && i <= l && j <= l && k <= l;
*/
        
void foo304_c71(unsigned int n) {

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
      loop invariant (0 < \at(n,Pre)) ==> counts_partition(l, v3, v4, i, j, k, \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
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
