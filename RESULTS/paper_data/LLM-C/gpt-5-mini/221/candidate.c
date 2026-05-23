int findOddPair(int * arr, int arr_len, int n);

/*@
    requires arr_len >= 0;
    requires \valid_read(arr + (0 .. arr_len-1)) || arr_len == 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (arr_len * (arr_len - 1)) / 2;
    ensures \result == 
        (\sum integer c; 0 <= c < arr_len;
            (\sum integer index; c+1 <= index < arr_len;
                ((arr[c] ^ arr[index]) % 2 == 1) ? 1 : 0));
*/
int findOddPair(int * arr, int arr_len, int n) {

        int found = 0;
        int offset = arr_len;
        /*@ 
            loop invariant 0 <= offset == arr_len;
            loop invariant 0 <= c <= offset;
            loop invariant 0 <= found <= (arr_len * (arr_len - 1)) / 2;
            loop invariant found == 
                (\sum integer i; 0 <= i < c;
                    (\sum integer j; i+1 <= j < offset;
                        ((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0));
            loop assigns c, found, offset;
            loop variant offset - c;
        */
        for (int c = 0; c < offset; c++) {
                /*@ 
                    loop invariant c+1 <= index <= offset;
                    loop invariant 0 <= found <= (arr_len * (arr_len - 1)) / 2;
                    loop invariant found == 
                        (\sum integer i; 0 <= i < c;
                            (\sum integer j; i+1 <= j < offset;
                                ((arr[i] ^ arr[j]) % 2 == 1) ? 1 : 0))
                        + 
                        (\sum integer j; c+1 <= j < index;
                            ((arr[c] ^ arr[j]) % 2 == 1) ? 1 : 0);
                    loop assigns index, found;
                    loop variant offset - index;
                */
                for (int index = c + 1; index < offset; index++) {
                        if ((arr[c] ^ arr[index]) % 2 == 1) {
                                found++;
                        }
                }
        }
        return found;
}
