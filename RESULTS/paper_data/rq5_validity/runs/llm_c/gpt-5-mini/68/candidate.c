/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void foo306(unsigned int n) {

    unsigned int j;
    unsigned int i;
    unsigned int l;

    i = 0;
    j = 0;
    l = 0;

    /*@
        loop invariant 0 <= l <= n;
        loop invariant 0 <= i <= l;
        loop invariant 0 <= j <= l;
        loop invariant i + j == l;
        loop assigns i, j, l;
        loop variant n - l;
    */
    while (l < n) {
       if ((l % 2) == 0) {
       i = i + 1;
      }
       else{
       j = j + 1;
      }
       l = l + 1;
      }

  }
