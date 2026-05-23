/*@
    requires n >= 0;
    assigns i, j, k, v1, v2, v3, v4, v5, v6, l;
    ensures l == n;
    ensures v6 == \sum(0, n-1, \lambda integer x; x % 9 == 0 ? 1 : 0);
    ensures v5 == \sum(0, n-1, \lambda integer x; x % 8 == 0 && x % 9 != 0 ? 1 : 0);
    ensures v1 == \sum(0, n-1, \lambda integer x; x % 7 == 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures v2 == \sum(0, n-1, \lambda integer x; x % 6 == 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures v3 == \sum(0, n-1, \lambda integer x; x % 5 == 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures v4 == \sum(0, n-1, \lambda integer x; x % 4 == 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures i == \sum(0, n-1, \lambda integer x; x % 3 == 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures j == \sum(0, n-1, \lambda integer x; x % 2 == 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
    ensures k == \sum(0, n-1, \lambda integer x; x % 2 != 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
*/
void foo313(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int v4;
    unsigned int v3;
    unsigned int v2;
    unsigned int v1;
    unsigned int v5;
    unsigned int v6;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;
    v4 = 0;
    v3 = 0;
    v2 = 0;
    v1 = 0;
    v5 = 0;
    v6 = 0;

    /*@
        loop invariant 0 <= l <= n;
        loop invariant v6 == \sum(0, l-1, \lambda integer x; x % 9 == 0 ? 1 : 0);
        loop invariant v5 == \sum(0, l-1, \lambda integer x; x % 8 == 0 && x % 9 != 0 ? 1 : 0);
        loop invariant v1 == \sum(0, l-1, \lambda integer x; x % 7 == 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant v2 == \sum(0, l-1, \lambda integer x; x % 6 == 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant v3 == \sum(0, l-1, \lambda integer x; x % 5 == 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant v4 == \sum(0, l-1, \lambda integer x; x % 4 == 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant i == \sum(0, l-1, \lambda integer x; x % 3 == 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant j == \sum(0, l-1, \lambda integer x; x % 2 == 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop invariant k == \sum(0, l-1, \lambda integer x; x % 2 != 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 && x % 8 != 0 && x % 9 != 0 ? 1 : 0);
        loop assigns l, v6, v5, v1, v2, v3, v4, i, j, k;
        loop variant n - l;
    */
    while (l < n) {
       if((l % 9) == 0){
       v6 = v6 + 1;
      }
       else if((l % 8) == 0){
       v5 = v5 + 1;
      }
       else if((l % 7) == 0){
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
       else if((l % 2 == 0)){
       j = j + 1;
      }
       else{
       k = k + 1;
      }
       l = l + 1;
      }

  }
