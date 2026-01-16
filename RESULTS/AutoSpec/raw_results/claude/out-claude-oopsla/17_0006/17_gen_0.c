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
 loop invariant 1 <= i <= n+1;
 loop invariant k == (i * (i - 1)) / 2;
 loop assigns i;
 loop assigns j;
 loop assigns k;
 */
 while(i < n) {
  j = 0;
  /*@
  loop invariant k == (i * (i + 1)) / 2;
  loop invariant j <= i;
  loop invariant i <= n;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 // @ assert k >= n;
 
}
