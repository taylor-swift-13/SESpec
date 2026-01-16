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
    /*@
    loop assigns i;
    loop assigns k;
    */
    for (j=i;j<n;j++)
      /*@
      loop invariant k >= j && k <= n;
      loop invariant j >= i && j <= n;
      loop invariant i >= 0 && i <= n;
      loop invariant i <= k;
      loop assigns k;
      */
      for (k=j;k<n;k++){
	      // @ assert k>=i;
      }
}
