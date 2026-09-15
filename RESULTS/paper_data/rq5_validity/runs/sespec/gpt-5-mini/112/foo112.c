
#include <string.h>
#include <stddef.h>

/*@
  logic integer mask_of_segment(const char *s, integer lo, integer hi) =
    lo >= hi ? 0
             : mask_of_segment(s, lo, hi - 1) |
               ( ('a' <= s[hi-1] && s[hi-1] <= 'z') ? (1 << (s[hi-1] - 'a')) : 0 );
*/

/*@ 
  predicate all_lower_and_distinct{L}(const char *s, integer lo, integer hi) =
    lo >= hi ? \true
             : ( 'a' <= s[lo] && s[lo] <= 'z'
                 && (\forall integer j; lo < j < hi ==> s[lo] != s[j])
                 && all_lower_and_distinct{L}(s, lo+1, hi) );

  requires \valid_read(str + (0 .. (int)strlen(str)-1));
  assigns \nothing;
  ensures ( (int)strlen(str) > 26 ) ==> \result == 0;
  ensures ( (int)strlen(str) <= 26 ) ==>
            ( \result == 1 <==> all_lower_and_distinct(str, 0, (int)strlen(str)) );
*/
int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= len;
          loop invariant 0 <= num && num <= ((1 << 26) - 1);
          loop invariant num == mask_of_segment(str, 0, i);
          loop invariant \forall integer k; 0 <= k < len ==> str[k] == \at(str[k], Pre);
          loop assigns i, num;
            */
            for (int i = 0; i < len; i++) {
            char c = str[i];
            int index = c - 'a';
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
            
        return 1;
}
