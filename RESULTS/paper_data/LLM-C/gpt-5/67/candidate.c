/*@ 
  requires \true;
  assigns \nothing;
*/
void foo300(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= k;
      loop invariant i % 3 == 0;
      loop invariant j % 3 == 0;
      loop invariant k % 3 == 0;
      loop invariant j + k == i;
      loop invariant j >= k;
      loop invariant 0 <= j - k <= 3;
      loop invariant (i % 6 == 0 ==> j - k == 0);
      loop invariant (i % 6 == 3 ==> j - k == 3);
      loop assigns i, j, k;
      loop variant n - i;
    */
    while(i < n){
       i = i + 3;
       if((i % 2) != 0)
       j = j + 3;
       else
       k = k + 3;
      }

    /*@ assert j + k == i; */
    /*@ assert i % 3 == 0 && j % 3 == 0 && k % 3 == 0; */
    /*@ assert n <= 0 ==> (i == 0 && j == 0 && k == 0); */
    /*@ assert n > 0 ==> (i >= n && i - 3 < n); */
    /*@ assert j >= k && 0 <= j - k <= 3; */
    /*@ assert (i % 6 == 0 ==> j == k) && (i % 6 == 3 ==> j == k + 3); */

  }
