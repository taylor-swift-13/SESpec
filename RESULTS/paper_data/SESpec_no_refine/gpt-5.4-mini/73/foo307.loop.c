
/*@ logic integer count7(integer l) = l / 7; */
/*@ logic integer count6(integer l) = l / 6 - l / 42; */
/*@ logic integer count5(integer l) = l / 5 - l / 35; */
/*@ logic integer count4(integer l) = l / 4 - l / 28; */
/*@ logic integer count3(integer l) = l / 3 - l / 21 - l / 15 + l / 105; */
/*@ logic integer count2(integer l) = l / 2 - l / 14 - l / 10 - l / 6 + l / 70 + l / 42 + l / 30 - l / 210; */
/*@ logic integer count1(integer l) =
      l - l / 2 - l / 3 - l / 4 - l / 5 - l / 6 - l / 7
      + l / 10 + l / 12 + l / 14 + l / 15 + l / 18 + l / 20 + l / 21 + l / 28 + l / 30 + l / 35 + l / 42
      - l / 60 - l / 70 - l / 84 - l / 105 - l / 140 - l / 210 + l / 420; */

void foo307(unsigned int n) {

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
      loop invariant 0 <= l <= n;
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
