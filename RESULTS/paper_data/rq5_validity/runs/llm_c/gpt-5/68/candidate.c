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

    /*@ assert i == 0 && j == 0 && l == 0; */

    /*@
      loop invariant 0 <= l <= n;
      loop invariant i + j == l;
      loop invariant i == (l + 1) / 2;
      loop invariant j == l / 2;
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

    /*@ assert l == n; */
    /*@ assert i == (n + 1) / 2; */
    /*@ assert j == n / 2; */
    /*@ assert i + j == n; */

  }
