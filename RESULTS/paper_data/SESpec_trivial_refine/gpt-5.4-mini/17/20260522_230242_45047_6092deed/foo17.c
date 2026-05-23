
#include <stdlib.h>

/*@
  assigns \result \from index;
*/
int foo17(int index);


/*@
  assigns \result \from index;
  ensures (index < 0 || index >= 4) ==> \result == 0;
  ensures 0 <= index < 4 ==> \result == 1;
*/
int foo17(int index)
{
    if (index < 0 || index >= 4) return 0;
    return 1;
}
