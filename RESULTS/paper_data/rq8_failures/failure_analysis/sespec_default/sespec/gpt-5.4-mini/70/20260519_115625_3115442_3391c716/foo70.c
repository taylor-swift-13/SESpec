
/*@ logic integer count_mod4(integer n) = n / 4 + (n % 4 > 0 ? 1 : 0); */

/*@ logic integer count_div4(integer n) = n / 4; */

/*@ logic integer count_div3_not4(integer n) =
      (n / 3) - (n / 12); */

/*@ logic integer count_div2_not3_not4(integer n) =
      (n / 2) - (n / 4) - (n / 6) + (n / 12); */

/*@ logic integer count_other(integer n) =
      n - count_div4(n) - count_div3_not4(n) - count_div2_not3_not4(n); */

void foo70(unsigned int n) {

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
      loop invariant 0 <= l <= n;
      loop invariant n == \at(n,Pre);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
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
