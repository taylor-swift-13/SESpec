#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * "nested5.c" from InvGen test suite
 */

void main() {
  int i,j,k,n;
  
  for (i=0;i<n;i++)
    for (j=i;j<n;j++)
      /*@
      loop invariant k <= n;
      loop invariant j <= n;
      loop invariant j <= k;
      loop invariant i >= 0 && j >= i && k >= j && n >= 0;
      loop invariant i <= n;
      loop invariant i <= j;
      loop invariant 0 <= i;
      loop assigns k;
      */
      for (k=j;k<n;k++){
	      // @ assert k>=i;
      }
}
