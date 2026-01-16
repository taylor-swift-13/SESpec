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
 loop invariant 1 <= i <= n;
 loop invariant k == 1 + (i-1)*i/2;
 loop invariant 0 <= j <= i;
 loop invariant k >= 1 + (i*(i-1))/2;
 loop invariant j <= i;
 loop invariant k >= j*(i - (j-1)/2);
 loop invariant 1 <= i;
 */
 while(i < n) {
  j = 0;
  /*@
  loop invariant j <= i;
  loop invariant i <= n;
  loop invariant 1 <= i;
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
