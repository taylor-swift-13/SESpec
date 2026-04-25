#include <string.h>

int foo46(const char * pat, const char * txt);

int foo46(const char * pat, const char * txt) {

        int i = 0;

        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i) != txt[i))
                return 0;
            i = i + 1;
        }

        return 1;
}
