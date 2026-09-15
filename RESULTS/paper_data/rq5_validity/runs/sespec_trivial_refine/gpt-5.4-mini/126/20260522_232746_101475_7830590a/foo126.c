
/*@ predicate cstring_readable{L}(const char *s) =
      \exists integer n; \valid_read(s + (0 .. n)) && s[n] == '\0';
*/
/*@ 
  logic boolean is_jewel_char{L}(const char *jewels, integer jewelsLength, char c) =
    (\exists integer j; 0 <= j < jewelsLength && jewels[j] == c);

  logic integer count_matching_stones{L}(const char *jewels, integer jewelsLength,
                                         const char *stones, integer n) =
    n <= 0 ? 0 :
    count_matching_stones(jewels, jewelsLength, stones, n - 1)
      + (is_jewel_char(jewels, jewelsLength, stones[n - 1]) ? 1 : 0);
*/

        
/*@
  requires cstring_readable(jewels);
  requires cstring_readable(stones);
  assigns \nothing;
  ensures \result == count_matching_stones(jewels, (int)strlen(jewels), stones, (int)strlen(stones));
  ensures \result >= 0;
  ensures \result <= (int)strlen(stones);
  ensures \result == \null ==> \false;
*/
int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
        /*@
          loop invariant 0 <= i <= stonesLength;
          loop invariant 0 <= jewelsCount <= i;
          loop invariant jewelsCount == count_matching_stones(jewels, jewelsLength, stones, i);
          loop assigns i, jewelsCount, stone, jewel, j;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            /*@
              loop invariant 0 <= j <= jewelsLength;
              loop invariant 0 <= jewelsCount <= i + 1;
              loop assigns j, jewelsCount, jewel;
            */
            for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j];
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
            
        }
            
        return jewelsCount;
}
