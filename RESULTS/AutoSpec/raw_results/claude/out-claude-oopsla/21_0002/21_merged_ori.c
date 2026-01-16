#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * Based on "larg_const.c" from InvGen test suite  
 */
/*@
requires n > 0;
requires n < 10;
*/
void foo(int n) {
  int c1 = 4000;
  int c2 = 2000;
  int v;
  int i, k, j;
  k = 0;
  i = 0;
  /*@
  loop invariant v == 0 || v == 1;
  loop invariant k == i * c1 || k == i * c2 || (0 < i && k >= i * c2 && k <= i * c1);
  loop invariant k <= 4000 * i;
  loop invariant k % 1000 == 0;
  loop invariant i > 0 ==> k >= c2;
  loop invariant c2 == 2000;
  loop invariant c1 == 4000;
  loop invariant 2000 * i <= k;
  ```c;
  ```;
  Looking at this code, I need to generate loop invariants that differ from the existing ones and describe relationships between variables `c1`, `c2`, `v`, `i`, `k`, and `n`.;
  loop invariant i <= n;
  loop invariant 0 <= i;
  loop assigns v;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
    i++;
    if(unknown2() % 2 == 0) 
      v = 0;
    else v = 1;
    
    if( v == 0 )
      k += c1;
    else 
      k += c2;
  }
  
  // @ assert k > n;
}

