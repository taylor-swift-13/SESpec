
/*@
  requires \valid_read(jewels);
  requires \valid_read(stones);
  assigns \nothing;
  ensures \result >= 0;
*/
int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
        /*@
          loop invariant 0 <= i;
          loop invariant i <= stonesLength || stonesLength < 0;
          loop invariant jewelsCount >= 0;
          loop assigns i, jewelsCount;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            /*@
              loop invariant 0 <= j;
              loop invariant j <= jewelsLength || jewelsLength < 0;
              loop invariant jewelsCount >= 0;
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
