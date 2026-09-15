int getPairsCount(int * pairs, int pairs_len, int num, int p);

 /*@
     requires num >= 0;
     requires pairs_len >= 0;
     requires num <= pairs_len;
     requires num == 0 || \valid(pairs + (0 .. num-1));
     assigns \nothing;
     ensures \result >= 0;
     ensures \result == (\sum integer ii; 0 <= ii < num;
                            (\sum integer jj; ii+1 <= jj < num;
                                (pairs[ii] + pairs[jj] == p) ? 1 : 0));
 */
int getPairsCount(int * pairs, int pairs_len, int num, int p) {

    int ret = 0;
    /*@
        loop invariant 0 <= index <= num;
        loop invariant ret == (\sum integer ii; 0 <= ii < index;
                                (\sum integer jj; ii+1 <= jj < num;
                                    (pairs[ii] + pairs[jj] == p) ? 1 : 0));
        loop assigns index, ret;
        loop variant num - index;
    */
    for (int index = 0; index < num; index++) {
        /*@
            loop invariant index+1 <= j <= num;
            loop invariant ret == (\sum integer ii; 0 <= ii < index;
                                    (\sum integer jj; ii+1 <= jj < num;
                                        (pairs[ii] + pairs[jj] == p) ? 1 : 0))
                             + (\sum integer jj; index+1 <= jj < j;
                                    (pairs[index] + pairs[jj] == p) ? 1 : 0);
            loop assigns j, ret;
            loop variant num - j;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                ret++;
            }
        }
    }
    return ret;
}
