/*@
  requires \true;
  assigns \nothing;
  ensures l == n;
  ensures v1 + v2 + v3 + v4 + i + j + k == n;
  ensures v1 == (n + 6) / 7;
  ensures v2 == ((n + 5) / 6) - ((n + 41) / 42);
  ensures 0 <= v1 <= n;
  ensures 0 <= v2 <= n;
  ensures 0 <= v3 <= n;
  ensures 0 <= v4 <= n;
  ensures 0 <= i <= n;
  ensures 0 <= j <= n;
  ensures 0 <= k <= n;
*/
void foo311(unsigned int n) {

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
      loop invariant v1 + v2 + v3 + v4 + i + j + k == l;
      loop invariant v1 == (l + 6) / 7;
      loop invariant v2 == ((l + 5) / 6) - ((l + 41) / 42);
      loop invariant 0 <= v1 <= l;
      loop invariant 0 <= v2 <= l;
      loop invariant 0 <= v3 <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= k <= l;
      loop assigns i, j, k, v1, v2, v3, v4, l;
      loop variant n - l;
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
