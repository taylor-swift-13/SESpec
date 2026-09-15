
/*@
  // No additional predicates or logic functions are needed for this program.
*/

/*@
  requires \valid(jewels + (0..strlen(jewels)-1));
  requires \valid(stones + (0..strlen(stones)-1));
  assigns jewelsCount;
  ensures \result == jewelsCount;
  ensures jewelsCount == \sum(0, strlen(stones)-1, 
      (\lambda integer i; (\exists integer j; 0 <= j < strlen(jewels) && stones[i] == jewels[j])));
*/
int foo126(const char * jewels, const char * stones) {

    int jewelsCount = 0;
    int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
    
    /*@
      loop invariant 0 <= i <= stonesLength;
      loop invariant jewelsCount >= 0;
      loop invariant jewelsCount == \sum(0, i-1, 
          (\lambda integer k; (\exists integer m; 0 <= m < jewelsLength && stones[k] == jewels[m])));
      loop assigns i, jewelsCount;
    */
    for (int i = 0; i < stonesLength; i++) {
        char stone = stones[i];
        
        /*@
          loop invariant 0 <= j <= jewelsLength;
          loop invariant \forall integer k; 0 <= k < j ==> stones[i] != jewels[k];
          loop assigns j;
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
