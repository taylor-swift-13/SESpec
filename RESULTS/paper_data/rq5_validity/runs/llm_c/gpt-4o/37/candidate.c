#include <stddef.h>

int data;
int checkInvariant();
int f();

/*@
    ensures \result == (&data != NULL);
    assigns \nothing;
*/
int checkInvariant() {
    return &data != NULL;
}

/*@
    ensures \result == 1;
    assigns \nothing;
*/
int f() {
    return checkInvariant();
}
