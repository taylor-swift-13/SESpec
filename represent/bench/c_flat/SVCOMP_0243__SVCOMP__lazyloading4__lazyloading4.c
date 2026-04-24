#include <stddef.h>

int checkInvariant();
int f();

int checkInvariant() {

    return data != NULL;
}

int f() {

    return Problem().checkInvariant();
}
