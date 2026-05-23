
/*@
  logic integer count_members{L}(char const *jewels, integer jl,
                                 char const *stones, integer hi) =
    hi <= 0 ? 0
            : count_members(jewels, jl, stones, hi - 1)
              + ((\exists integer k; 0 <= k < jl && stones[hi - 1] == jewels[k]) ? 1 : 0);
*/
        

/*@
  requires \valid(jewels);
  requires \valid(stones);
  assigns \nothing;
  ensures \result == count_members(jewels, (int)strlen(jewels), stones, (int)strlen(stones));
  ensures 0 <= \result;
  ensures \result <= (int)strlen(stones);
  ensures (int)strlen(stones) == 0 ==> \result == 0;
  ensures (int)strlen(jewels) == 0 ==> \result == 0;
  ensures (\forall integer t; 0 <= t < (int)strlen(stones) ==> (\exists integer k; 0 <= k < (int)strlen(jewels) && stones[t] == jewels[k])) ==> \result == (int)strlen(stones);
  ensures \result == \null ==> \true;
*/
int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= stonesLength;
          loop invariant 0 <= jewelsCount <= i;
          loop invariant jewelsCount == count_members(jewels, jewelsLength, stones, i);
          loop invariant \forall integer t; 0 <= t < i ==> (\exists integer k; 0 <= k < jewelsLength && stones[t] == jewels[k]) || \true;
          loop assigns i, stone, j, jewel, jewelsCount;
            */
            for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= jewelsLength;
          loop invariant 0 <= i <= stonesLength;
          loop invariant 0 <= jewelsCount <= i;
          loop invariant \forall integer t; 0 <= t < i ==> 
                           (\exists integer k; 0 <= k < jewelsLength && stones[t] == jewels[k]);
          loop assigns j, jewelsCount;
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
