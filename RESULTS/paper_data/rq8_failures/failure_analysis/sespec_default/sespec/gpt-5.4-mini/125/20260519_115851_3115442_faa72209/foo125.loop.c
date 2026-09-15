
/*@
  logic integer strlen(char *s) = *s == '\0' ? 0 : 1 + strlen(s + 1);
*/

int foo125(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        /*@
          loop invariant \forall integer k; 0 <= k < ((int)strlen(pat)) ==> pat[k] == \at(pat[k], Pre);
          loop invariant \forall integer k; 0 <= k < ((int)strlen(txt)) ==> txt[k] == \at(txt[k], Pre);
          loop assigns i;
        */
        while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}
