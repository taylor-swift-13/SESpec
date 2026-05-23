
#include <string.h>

/*@
  requires arg != \null;
  requires \valid_read(arg);

  behavior empty:
    assumes arg[0] == '\0';
    ensures \result == -1;

  behavior nonempty:
    assumes arg[0] != '\0';
    ensures \result == 1;

  complete behaviors;
  disjoint behaviors;
*/
int foo23(const char *arg);

int foo23(const char *arg) {
    if (arg[0] == '\0') return -1;
    unsigned short my_char = (unsigned short)arg[0];
    int x = my_char;
    if (!(x >= 0 && x <= 65535)) return 0;
    my_char = 65535;
    my_char++;
    if (my_char == 0) return 0;
    return 1;
}
