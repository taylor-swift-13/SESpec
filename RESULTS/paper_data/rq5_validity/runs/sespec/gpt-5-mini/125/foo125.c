
#include <string.h>

/*@
  predicate suffix_equal(const char *pat, const char *txt, integer m, integer n, integer i) =
    \forall integer k; i < k && k < m ==> pat[k] == txt[k - m + n];
*/

/*@ 
  requires pat != \null && txt != \null;
  requires \valid_read(pat + (0 .. ((int)strlen(pat) - 1)));
  requires \valid_read(txt + (0 .. ((int)strlen(txt) - 1)));
  assigns \nothing;
  ensures (\result == 1) <==> ( (int)strlen(txt) >= (int)strlen(pat) 
            && (\forall integer k; 0 <= k < (int)strlen(pat) 
                  ==> pat[k] == txt[k - (int)strlen(pat) + (int)strlen(txt)]) );
  ensures (\result == 0) <==> !((int)strlen(txt) >= (int)strlen(pat) 
            && (\forall integer k; 0 <= k < (int)strlen(pat) 
                  ==> pat[k] == txt[k - (int)strlen(pat) + (int)strlen(txt)]));
*/
int foo125(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant -1 <= i && i <= (int)strlen(pat) - 1;
          loop invariant (i >= 0) ==> suffix_equal(pat, txt, (int)strlen(pat), (int)strlen(txt), i);
          loop invariant (!(i >= 0)) ==> suffix_equal(pat, txt, (int)strlen(pat), (int)strlen(txt), -1);
          loop invariant \forall integer k; 0 <= k < (int)strlen(pat) ==> \valid_read(pat + k);
          loop invariant \forall integer k; 0 <= k < (int)strlen(txt) ==> \valid_read(txt + k);
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
