#include <assert.h>
int unknown1();
int unknown2();
int unknown3();

/*
 *  Based on "Automatically refining abstract interpretations" fig.1
 */


void main() {
 int x = 0, y = 0;
 /*@
 loop invariant y == 100 * x || y > 2;
 loop invariant x < 4 || y > 2;
 loop invariant 0 <= y;
 loop invariant 0 <= x;
 loop invariant (x >= 4) ==> (y > 2);
 loop invariant (x < 4) ==> (y <= 100 * x);
 loop invariant \true;
 loop assigns y;
 loop assigns x;
 */
 while(unknown1()) {
   if(unknown2()) { 
      x++; 
      y += 100; 
   }
   else if (unknown3()){ 
      if (x >= 4) { 
          x++; 
          y++; 
      } 
      if (x < 0) {
          y--;
      }
   }
  
 }
 //@ assert x < 4 || y > 2;
}
