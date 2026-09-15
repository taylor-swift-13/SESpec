
/*@
  logic integer count_matches(char *stones, integer lo, integer hi, char *jewels, integer jewels_len) =
    lo >= hi ? 0
             : count_matches(stones, lo, hi - 1, jewels, jewels_len)
               + (\exists integer t; 0 <= t < jewels_len && stones[hi-1] == jewels[t] ? 1 : 0);
*/

/*@ 
  predicate valid_cstring{L}(const char *s) = \exists integer n; n >= 0 && \valid(&s[0] + (0..n)) && s[n] == '\0';

  requires jewels != \null && stones != \null;
  requires valid_cstring{Pre}(jewels);
  requires valid_cstring{Pre}(stones);
  requires \valid(&jewels[0] + (0..(\at((integer)strlen(jewels),Pre))));
  requires \valid(&stones[0] + (0..(\at((integer)strlen(stones),Pre))));
  assigns \nothing;
  ensures \result == count_matches((char*)stones, 0, (integer)\at((int)strlen(stones),Pre), (char*)jewels, (integer)\at((int)strlen(jewels),Pre));
*/
int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i <= stonesLength;
            loop invariant 0 <= jewelsCount <= i;
            loop invariant jewelsCount == count_matches((char*)stones, 0, i, (char*)jewels, jewelsLength);
            loop invariant \forall integer k; 0 <= k < jewelsLength ==> jewels[k] == jewels[k];
            loop invariant \forall integer k; 0 <= k < stonesLength ==> stones[k] == stones[k];
            loop assigns i, stone, j, jewel, jewelsCount;
            */
            for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i <= stonesLength;
            loop invariant 0 <= jewelsCount <= i;
            loop assigns i, jewelsCount, stone;
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
