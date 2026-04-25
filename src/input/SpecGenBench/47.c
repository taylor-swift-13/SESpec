#include <string.h>

int foo47(const char * s, const char * t);

int foo47(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s[i) == t[j)) {
                i++;
            }
            j++;
        }
        return i == n;
}
