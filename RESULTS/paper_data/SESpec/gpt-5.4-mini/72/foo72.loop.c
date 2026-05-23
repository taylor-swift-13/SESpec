
void foo72(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;

    /*@
      loop invariant 0 <= l <= n;
      loop invariant v2 + v3 + v4 + i + j + k == l;
      loop invariant (\forall integer t; 0 <= t < l ==>
                        (t % 6 == 0) || (t % 5 == 0) || (t % 4 == 0) ||
                        (t % 3 == 0) || (t % 2 == 0) ||
                        (!(t % 6 == 0) && !(t % 5 == 0) && !(t % 4 == 0) &&
                         !(t % 3 == 0) && !(t % 2 == 0)));
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant (0 < \at(n,Pre)) ==> (j <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (i <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (k <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v3 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v2 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v2, v3, v4, i, j, k, l;
    */
    while (l < n) {
       if((l % 6) == 0){
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
