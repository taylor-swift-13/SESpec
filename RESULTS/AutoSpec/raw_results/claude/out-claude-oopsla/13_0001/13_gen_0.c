#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * Based on "Property-Directed Incremental Invariant Generation" by Bradley et al.
 */

void foo(int flag) {
   int j = 2; 
   int k = 0;

   /*@
   loop invariant j >= 2;
   loop invariant k >= 0;
   loop invariant (flag && k == 0) || j == 2 * k + 2;
   loop assigns j;
   loop assigns k;
   */
   while(unknown1()){ 
     if (flag)
       j = j + 4;
     else {
       j = j + 2;
       k = k + 1;
     }
   }
   if(k != 0) {
     // @ assert j == 2 * k + 2;
   }
}
