public class GetPairsCount {

    /*@
      @ requires pairs != null;
      @ requires 0 <= num && num <= pairs.length;
 
      @   (\sum int i; 0 <= i && i < num;
      @        (\num_of int j; i + 1 <= j && j < num && pairs[i] + pairs[j] == p; true))
      @   - 0;
      @*/
    public static int getPairsCount(int[] pairs, int num, int p) {
        int count = 0;
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num; j++) {
                if (pairs[i] + pairs[j] == p) {
                    count++;
                }
            }
        }
        return count;
    }
}