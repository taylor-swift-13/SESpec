#include <limits.h>
#include <string.h>


/*@
  requires \valid(arg);
  assigns \nothing;
*/

/*@requires \exists integer n; n >= 0 && \valid_read(arg + (0 .. n)) && arg[n] == 0;
  assigns \nothing;*/
int stub_A(const char *arg);

/*@requires strlen(arg) >= 1;
requires arg != \null;
requires \valid_read(arg);
requires \valid_read(arg + (0..strlen(arg)));
requires \valid_read(arg + (0 .. strlen(arg)));
ensures \result == 1 ==> strlen(arg) >= 1;
ensures \result == 0 || \result == 1 || \result == -1;
ensures \result == 0 ==> strlen(arg) >= 1;
assigns \nothing;*/
int stub_B(const char *arg);

/*@requires strlen(arg) >= 1;
requires arg != \null;
requires \valid_read(arg);
requires \valid_read(arg + (0..strlen(arg)));
requires \valid_read(arg + (0 .. strlen(arg)));
ensures \result == 1 ==> strlen(arg) >= 1;
ensures \result == 0 || \result == 1 || \result == -1;
ensures \result == 0 ==> strlen(arg) >= 1;
assigns \nothing;*/
int check_A_implies_B(const char *arg) {
    return stub_A(arg);
}

/*@requires \exists integer n; n >= 0 && \valid_read(arg + (0 .. n)) && arg[n] == 0;
  assigns \nothing;*/
int check_B_implies_A(const char *arg) {
    return stub_B(arg);
}
