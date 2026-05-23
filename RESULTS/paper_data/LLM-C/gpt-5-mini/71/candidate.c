/*@
    requires \true;
    assigns \nothing;
    ensures l == n;
    ensures v3 == (\sum integer t; 0 <= t < n; (t % 5 == 0) ? 1 : 0);
    ensures v4 == (\sum integer t; 0 <= t < n; (t % 5 != 0 && t % 4 == 0) ? 1 : 0);
    ensures i == (\sum integer t; 0 <= t < n; (t % 5 != 0 && t % 4 != 0 && t % 3 == 0) ? 1 : 0);
    ensures j == (\sum integer t; 0 <= t < n; (t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0) ? 1 : 0);
    ensures k == (\sum integer t; 0 <= t < n; (t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0) ? 1 : 0);
*/
void foo309(unsigned int n) {

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
        loop invariant 0 <= l <= n;
        loop invariant v3 == (\sum integer t; 0 <= t < l; (t % 5 == 0) ? 1 : 0);
        loop invariant v4 == (\sum integer t; 0 <= t < l; (t % 5 != 0 && t % 4 == 0) ? 1 : 0);
        loop invariant i == (\sum integer t; 0 <= t < l; (t % 5 != 0 && t % 4 != 0 && t % 3 == 0) ? 1 : 0);
        loop invariant j == (\sum integer t; 0 <= t < l; (t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 == 0) ? 1 : 0);
        loop invariant k == (\sum integer t; 0 <= t < l; (t % 5 != 0 && t % 4 != 0 && t % 3 != 0 && t % 2 != 0) ? 1 : 0);
        loop assigns l, i, j, k, v3, v4;
        loop variant n - l;
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
