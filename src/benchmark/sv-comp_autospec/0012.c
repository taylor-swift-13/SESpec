
#include <limits.h>

int unknown1();

/*@
requires l > 0;
requires l < INT_MAX;
requires n < INT_MAX;
*/
void foo0012(int n, int l) {
  int k = 1;

  
  for (; k < n; k++){

    int i= l;
    
    for (; i < n; i++){
      /*@ assert 1 <= i;*/
    }
    if(unknown1()) {
      l = l + 1;
    }
  }
}
