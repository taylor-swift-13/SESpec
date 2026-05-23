#include <stddef.h>

int data;
int foo57_helper1();
int foo57();

#include <stddef.h>

int data;
int foo57_helper1();
int foo57();


/*@
  assigns \nothing;
  ensures \result == 1;
*/
int foo57_helper1() {
    return &data != NULL;
}


int foo57() {
    return foo57_helper1();
}