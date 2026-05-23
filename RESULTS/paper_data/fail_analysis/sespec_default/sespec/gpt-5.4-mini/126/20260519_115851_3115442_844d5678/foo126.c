
        /*@
        logic integer count_matches(const char *jewels, integer jewelsLength,
                                    const char *stones, integer stonesLength) =
          stonesLength <= 0 ? 0 :
          count_matches(jewels, jewelsLength, stones, stonesLength - 1) +
          (\exists integer k; 0 <= k < jewelsLength && stones[stonesLength - 1] == jewels[k] ? 1 : 0);
        */
        

/*@
  requires \valid(&jewels[0] + (0..stones-1));
  requires \forall integer i; 0 <= i < stones ==> 0 <= jewels[i] <= 100;
  requires stones > 0;
  requires stones < 100;
  requires \valid(&stones[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= stones[i] <= 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/

int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= stonesLength;
              loop invariant 0 <= jewelsCount <= i;
              loop invariant jewelsCount == count_matches(jewels, jewelsLength, stones, i);
              loop assigns i, jewelsCount;
            */
            for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= stonesLength;
              loop invariant 0 <= jewelsCount <= i;
              loop assigns i, jewelsCount;
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
