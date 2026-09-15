/*@
  requires k >= 0;
  assigns \nothing;
  ensures n == 2 * k;
  ensures i == \old(i) + k;
  ensures j == \old(j) + k;
  ensures b == 0;
*/
void foo181(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant 0 <= n <= 2 * k;
      loop invariant i == \old(i) + n / 2;
      loop invariant j == \old(j) + (n + 1) / 2;
      loop invariant b == n % 2;
      loop assigns n, b, i, j;
      loop variant 2 * k - n;
    */
    while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
       b = 0;
       i = i + 1;
      }
       else{
       b = 1;
       j = j + 1;
      }
      }

  }
