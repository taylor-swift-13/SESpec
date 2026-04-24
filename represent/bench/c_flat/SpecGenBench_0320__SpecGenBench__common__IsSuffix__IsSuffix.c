#include <string.h>

int isSuffix(const char * pat, const char * txt);

int isSuffix(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i) != txt[j))
                return 0;
            i = i - 1;
        }

        return 1;
}
