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
 y >= 0 || y <= y + 100;
 loop invariant;
 loop assigns y;
 loop assigns x;
 \min(0, x) <= x <= \max(x, x + 1);
 (x < 4) || (y > 2);
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
 // @ assert x < 4 || y > 2;
}
