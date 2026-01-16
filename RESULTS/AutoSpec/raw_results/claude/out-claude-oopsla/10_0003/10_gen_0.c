#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {


  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  /*@
  loop invariant w == 1 || w == 0;
  loop invariant w == 1 ==> x == y + 1;
  loop invariant w == 0 ==> x == y;
  loop invariant z == 0 || z == 1;
  loop invariant z == 0 ==> x == y;
  loop invariant z == 1 ==> x == y + 1;
  loop invariant x >= y;
  loop invariant y >= 0;
  loop invariant x >= 0 && y >= 0;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  loop assigns w;
  */
  while(unknown2()){
  	if(w) {
  	  x++;
  	  w = !w;
	  }
	
    if(!z) {
      y++; 
      z=!z;
    }
  }

  // @ assert x==y;
  
}
