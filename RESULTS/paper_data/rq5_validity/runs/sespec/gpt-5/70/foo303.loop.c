
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
      loop invariant 0 <= l <= n;
      loop invariant v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
      loop invariant v4 + i + j + k == l;
      loop invariant (l == 0) ==> (v4 == 0 && i == 0 && j == 0 && k == 0);
      loop invariant (0 < \at(n,Pre)) ==> (v4 + i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (j >= 0 && j <= l) ;
      loop invariant (0 < \at(n,Pre)) ==> (i >= 0 && i <= l) ;
      loop invariant (0 < \at(n,Pre)) ==> (k >= 0 && k <= l) ;
      loop invariant (0 < \at(n,Pre)) ==> (v4 >= 0 && v4 <= l) ;
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre)) ;
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
