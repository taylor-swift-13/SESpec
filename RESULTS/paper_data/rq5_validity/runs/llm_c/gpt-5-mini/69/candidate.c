/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void foo307(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int k;
    unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    /*@
        loop invariant 0 <= l <= n;
        loop invariant i >= 0 && j >= 0 && k >= 0;
        loop invariant i + j + k == l;
        loop invariant i == \sum integer t; 0 <= t < l ? ((t % 3) == 0 ? 1 : 0) : 0;
        loop invariant j == \sum integer t; 0 <= t < l ? (((t % 3) != 0 && (t % 2) == 0) ? 1 : 0) : 0;
        loop assigns l, i, j, k;
        loop variant n - l;
    */
    while (l < n) {
       if ((l % 3) == 0) {
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
