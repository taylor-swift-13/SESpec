
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
      loop invariant 0 <= l && l <= n;
      loop invariant 0 <= i && 0 <= j && 0 <= k && 0 <= v3 && 0 <= v4;
      loop invariant i + j + k + v3 + v4 == l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant (i > 0) ==> (\exists unsigned int x; 0 <= x < l && (x % 3 == 0));
      loop invariant (j > 0) ==> (\exists unsigned int x; 0 <= x < l && (x % 2 == 0));
      loop invariant (k > 0) ==> (\exists unsigned int x; 0 <= x < l && (x % 2 != 0) && (x % 3 != 0) && (x % 4 != 0) && (x % 5 != 0));
      loop invariant (v3 > 0) ==> (\exists unsigned int x; 0 <= x < l && (x % 5 == 0));
      loop invariant (v4 > 0) ==> (\exists unsigned int x; 0 <= x < l && (x % 4 == 0));
      loop invariant (l == n) ==> (i + j + k + v3 + v4 == n);
      loop invariant (0 < \at(n,Pre)) ==> (i + j + k + v3 + v4 == l);
      loop invariant (0 < \at(n,Pre)) ==> (j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i && i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k && k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 && v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v3 && v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l && l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0) && (v3 == 0) && (v4 == 0) && (k == 0) && (i == 0) && (j == 0) && (n == \at(n,Pre)));
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
