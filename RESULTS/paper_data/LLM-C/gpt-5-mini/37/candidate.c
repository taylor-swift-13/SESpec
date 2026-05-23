#include <stddef.h>

int data;
int checkInvariant();
int f();

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int checkInvariant() {
    return &data != NULL;
}

/*@
    assigns \nothing;
    ensures \result != 0;
*/
int f() {
    return checkInvariant();
}
