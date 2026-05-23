
#include <string.h>

/*@ logic boolean prefix_equal(char *a, char *b, integer n) =
      n <= 0 ? \true :
      prefix_equal(a, b, n - 1) && a[n - 1] == b[n - 1];
*/

 /*@
  requires \exists integer n; 0 <= n && \valid_read(pat + (0 .. n)) && pat[n] == '\0';
  requires \exists integer m; 0 <= m && \valid_read(txt + (0 .. m)) && txt[m] == '\0';
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int foo123(const char * pat, const char * txt) {

        int i = 0;

        /*@
          loop invariant 0 <= i;
          loop invariant prefix_equal((char *)pat, (char *)txt, i);
          loop invariant i == 0 || pat[i-1] == txt[i-1];
          loop invariant pat == \at(pat, Pre);
          loop invariant txt == \at(txt, Pre);
          loop assigns i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
