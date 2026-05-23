class Sespec0126 {
    //@ requires jewels != null && stones != null;
    //@ ensures 0 <= \result && \result <= stones.length;
    //@ ensures \result == (\sum int ii; 0 <= ii && ii < stones.length; ((\exists int jj; 0 <= jj && jj < jewels.length; stones[ii] == jewels[jj]) ? 1 : 0));
    //@ assignable \nothing;
    static int foo126(char[] jewels, char[] stones) {
        int jewelsCount = 0;
        int jewelsLength = jewels.length, stonesLength = stones.length;
        //@ maintaining 0 <= i && i <= stonesLength;
        //@ maintaining jewelsLength == jewels.length && stonesLength == stones.length;
        //@ maintaining jewelsCount == (\sum int k; 0 <= k && k < i; ((\exists int jj; 0 <= jj && jj < jewelsLength; stones[k] == jewels[jj]) ? 1 : 0));
        //@ decreases stonesLength - i;
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            //@ maintaining 0 <= j && j <= jewelsLength;
            //@ maintaining jewelsLength == jewels.length && stonesLength == stones.length;
            //@ maintaining (\forall int t; 0 <= t && t < j; jewels[t] != stone);
            //@ decreases jewelsLength - j;
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
}