
/*@
  requires \valid(&jewels[0] + (0..stones-1));
  requires \forall integer i; 0 <= i < stones ==> 0 <= jewels[i] <= 100;
  requires stones > 0;
  requires stones < 100;
  requires \valid(&stones[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= stones[i] <= 100;
*/

int foo126(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        
        /*@
          loop invariant 0 <= i <= stonesLength;
          loop invariant jewelsCount >= 0;
          loop assigns i, stone, j, jewel, jewelsCount;
        */
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            
            /*@
              loop invariant 0 <= j <= jewelsLength;
              loop invariant jewelsCount >= 0;
              loop assigns j, jewel, jewelsCount;
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
