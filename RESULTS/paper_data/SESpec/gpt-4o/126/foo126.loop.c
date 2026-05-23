
/*@
  // No additional predicates or logic functions are needed for this program.
*/

/*@
  requires \valid(jewels + (0..strlen(jewels)-1));
  requires \valid(stones + (0..strlen(stones)-1));
*/
int foo126(const char * jewels, const char * stones) {

    int jewelsCount = 0;
    int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
    
    /*@
      loop invariant 0 <= i <= stonesLength;
      loop invariant jewelsCount >= 0;
      loop invariant \forall integer k; 0 <= k < i ==> 
          (\exists integer m; 0 <= m < jewelsLength && stones[k] == jewels[m]);
      loop assigns i, jewelsCount, stone;
    */
    for (int i = 0; i < stonesLength; i++) {
        char stone = stones[i];
        
        /*@
          loop invariant 0 <= j <= jewelsLength;
          loop invariant \forall integer k; 0 <= k < j ==> stones[i] != jewels[k];
          loop assigns j, jewel;
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
