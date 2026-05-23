#include <stddef.h>

/*@ public invariant data_is_nonnull: &data != NULL; */
int data;
int checkInvariant();
int f();

/*@ ensures \result == 1; */
int checkInvariant() {
    return &data != NULL;
}

/*@ ensures \result == 1; */
int f() {
    return checkInvariant();
}
