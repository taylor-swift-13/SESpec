
/*@ logic integer count_mod4(integer x) = x / 4 + ((x % 4) != 0 ? 1 : 0); */
/*@ logic integer count_mod3(integer x) = x / 3 + ((x % 3) != 0 ? 1 : 0); */
/*@ logic integer count_mod2(integer x) = x / 2 + ((x % 2) != 0 ? 1 : 0); */

void foo303(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;

    /*@
      loop invariant (0 < \at(n,Pre)) ==> (v4 == count_mod4(l));
      loop invariant (0 < \at(n,Pre)) ==> (l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;
    */
    while (l < n) {
       if ((l % 4) == 0) {
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
