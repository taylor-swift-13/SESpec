#include <stddef.h>

int data;
int foo57_helper1_c37();
int foo37();

#include <stddef.h>

int data;
int foo57_helper1_c37();
int foo37();


/*@
  assigns \nothing;
  ensures \result == 1;
  ensures \result == ((&data != \null) ? 1 : 0);
  ensures 0 <= \result && \result <= 1;
  ensures \result >= 0;
  ensures \valid(&data);
*/
int foo57_helper1_c37() {
    return &data != NULL;
}


/*@
  assigns \nothing;
    ensures \result == 1;
  ensures 0 <= \result && \result <= 1;
  ensures \result >= 0;
*/
int foo37() {
    return foo57_helper1_c37();
}