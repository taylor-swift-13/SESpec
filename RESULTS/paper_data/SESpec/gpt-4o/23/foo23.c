
#include <string.h>

/*@
  requires \valid(arg);
  assigns \nothing;
*/
int foo23(const char *arg);

/*@
  requires \valid(arg); 
  assigns \nothing;
  ensures \result == 1 ==> (strlen(arg) >= 1 && 
                            (arg[0] >= 0 && arg[0] <= 65535) && 
                            (65535 + 1 != 0));
*/
int foo23(const char *arg) {
    if (((int)strlen(arg)) < 1) return -1;
    unsigned short my_char = (unsigned short)arg[0];
    int x = my_char;
    if (!(x >= 0 && x <= 65535)) return 0;
    my_char = 65535;
    my_char++;
    if (my_char == 0) return 0;
    return 1;
}
