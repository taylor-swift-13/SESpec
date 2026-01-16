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
   Looking at the code and existing invariants, here are additional loop invariants that differ from the ones already provided:
   
   ```c
   loop invariant j >= 2;
   loop invariant k >= 0;
   loop invariant j % 2 == 0;
   loop invariant flag == 0 ==> k >= 0;
   loop invariant flag != 0 ==> (j % 4) == 2;
   loop invariant flag == 0 ==> j - 2 == 2 * k;
   loop invariant j == 2 + 2*k || (j - 2) % 4 == 0;
   loop invariant flag != 0 ==> k == 0;
   ```
   loop invariant 2 <= j;
   loop invariant 0 <= k;
   loop invariant ((flag == 0) ==> (j == 2*k + 2));
   loop invariant ((flag != 0) ==> (j >= 2));
   loop invariant ((flag != 0) ==> (j >= 2 + 4 * (j/4)));
   loop invariant ((flag != 0) ==> ( (j - 2) % 4 == 0 ));
   loop assigns k;
   loop assigns j;
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
