#include <string.h>

int foo45(const char * s);

int foo45(const char * s) {

        int n = ((int)strlen(s));

        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i) != s[n - 1 - i)) {
                return 0;
            }
        }

        return 1;
}
