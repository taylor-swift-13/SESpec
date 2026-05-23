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
*/
int foo57_helper1_c37() {
    return &data != NULL;
}


/*@
  assigns \nothing;
  ensures \result == 1;
*/
int foo37() {
    return foo57_helper1_c37();
}