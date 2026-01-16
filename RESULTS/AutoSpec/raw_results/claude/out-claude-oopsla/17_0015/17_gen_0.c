#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 /*@
 loop invariant 1 <= i;
 */
 while(i < n) {
  j = 0;
  /*@
  /*@ 
  loop invariant 0 <= j <= i;
  loop invariant k == (i*(i-1))/2 + 1;
  loop invariant k >= i;
  */
  loop invariant j <= i;
  loop invariant 0 <= j;
  */
  while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 // @ assert k >= n;
 
}
