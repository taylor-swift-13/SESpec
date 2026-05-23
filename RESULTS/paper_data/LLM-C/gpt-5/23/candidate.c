#include <string.h>

/*@ 
  requires arg != \null;
  requires \valid_read(arg + (0 .. strlen(arg)));
  assigns \nothing;
  behavior empty:
    assumes strlen(arg) < 1;
    ensures \result == -1;
  behavior nonempty:
    assumes strlen(arg) >= 1;
    ensures \result == 0 || \result == 1;
  complete behaviors;
  disjoint behaviors;
*/
int fun(const char *arg);

int fun(const char *arg) {
    /*@ assert arg != \null; */
    /*@ assert \valid_read(arg + (0 .. strlen(arg))); */
    if (((int)strlen(arg)) < 1) return -1;

    /*@ assert strlen(arg) >= 1; */
    /*@ assert \valid_read(arg + 0); */
    unsigned short my_char = (unsigned short)arg[0];
    int x = my_char;

    /*@ assert 0 <= my_char <= 65535; */
    /*@ assert x == (int)my_char; */
    /*@ assert 0 <= x <= 65535; */
    if (!(x >= 0 && x <= 65535)) return 0;

    my_char = 65535;
    /*@ assert my_char == 65535; */
    my_char++;
    /*@ assert my_char == 0; */
    if (my_char == 0) return 0;
    return 1;
}
