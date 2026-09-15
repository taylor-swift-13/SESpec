#include <stdlib.h>

int f();

/*@ 
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int f() {

    int *i = (int *)malloc(sizeof(int) * (10));
    /*@ assert i == \null || \valid(i + (0..9)); */
    int i_len = 10;
    /*@ assert i_len == 10; */
    /*@ assume i != \null; */
    /*@ assume \valid(i + (0..9)); */
    /*@ assume \initialized(i + 3); */
    return i[3] == 0;
}
