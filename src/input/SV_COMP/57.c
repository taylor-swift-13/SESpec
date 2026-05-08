#include <stddef.h>

int foo57_helper1();
int foo57();

int foo57_helper1() {

    void *data = NULL;
    return data != NULL;
}

int foo57() {

    return foo57_helper1();
}
