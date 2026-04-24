#include <string.h>

int f(const char * s1, const char * s2);

int f(const char * s1, const char * s2) {

    int i = 0;
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
      if (s1[count) == s2[i))
        return 0;
      ++i;
    }
    return 1;
}
