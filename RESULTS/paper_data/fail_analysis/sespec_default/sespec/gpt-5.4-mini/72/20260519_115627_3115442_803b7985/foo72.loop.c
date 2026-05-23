
/*@
  logic integer count_div6(integer x) = x <= 0 ? 0 : (x / 6) - (x / 30) - (x / 42) + (x / 210);
  logic integer count_div5(integer x) = x <= 0 ? 0 : (x / 5) - (x / 30) - (x / 10) + (x / 30);
  logic integer count_div4(integer x) = x <= 0 ? 0 : (x / 4) - (x / 20) - (x / 12) + (x / 60);
  logic integer count_div3(integer x) = x <= 0 ? 0 : (x / 3) - (x / 15) - (x / 6) + (x / 30);
  logic integer count_div2(integer x) = x <= 0 ? 0 : (x / 2) - (x / 6) - (x / 4) + (x / 12);
  logic integer count_other(integer x) = x <= 0 ? 0 : x - count_div6(x) - count_div5(x) - count_div4(x) - count_div3(x) - count_div2(x);
*/

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
      loop invariant n == \at(n,Pre);
      loop invariant v2 >= 0;
      loop invariant v3 >= 0;
      loop invariant v4 >= 0;
      loop invariant i >= 0;
      loop invariant j >= 0;
      loop invariant k == l - v2 - v3 - v4 - i - j;
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
