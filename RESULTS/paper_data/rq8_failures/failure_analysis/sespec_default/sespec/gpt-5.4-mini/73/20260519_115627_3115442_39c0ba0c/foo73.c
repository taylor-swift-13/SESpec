
/*@
  logic integer c7(integer x) = x / 7;
  logic integer c6(integer x) = x / 6;
  logic integer c5(integer x) = x / 5;
  logic integer c4(integer x) = x / 4;
  logic integer c3(integer x) = x / 3;
  logic integer c2(integer x) = x / 2;
*/

void foo73(unsigned int n) {

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
      loop invariant l <= n;
      loop invariant n == \at(n,Pre);
      loop invariant 0 <= v1;
      loop invariant 0 <= v2;
      loop invariant 0 <= v3;
      loop invariant 0 <= v4;
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= k;
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
