#include <stddef.h>

int data;
int foo57_helper1_c37();
int foo37();

int foo57_helper1_c37() {
    return &data != NULL;
}

int foo37() {
    return foo57_helper1_c37();
}
