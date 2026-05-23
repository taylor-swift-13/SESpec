/*@ 
  requires \true;

  assigns i, j, n, b;

  ensures b == 0;
  ensures n == (k > 0 ? 2*k : 0);
  ensures i == \old(i) + (k > 0 ? k : 0);
  ensures j == \old(j) + (k > 0 ? k : 0);
  ensures i + j == \old(i) + \old(j) + n;
*/
void foo181(int i, int j, int k) {

    int n;
    int b;

    n = 0;
    b = 0;

    /*@
      loop invariant 0 <= n;
      loop invariant (2*k > 0) ==> n <= 2*k;
      loop invariant b == n % 2;
      loop invariant i == \at(i,Pre) + n/2;
      loop invariant j == \at(j,Pre) + (n+1)/2;
      loop invariant i + j == \at(i,Pre) + \at(j,Pre) + n;
      loop assigns n, b, i, j;
      loop variant 2*k - n;
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
