int countPairs(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures \result == \sum(integer i=0, arr_len-2, \sum(integer j=i+1, arr_len-1, (arr[i] != arr[j] ? 1 : 0)));
  ensures 0 <= \result <= (arr_len * (arr_len - 1)) / 2;
*/
int countPairs(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        /*@ 
          loop invariant 0 <= i <= length;
          loop invariant length == arr_len;
          loop invariant length >= 0;
          loop invariant \valid_read(arr + (0 .. length - 1));
          loop invariant 0 <= count <= (length * (length - 1)) / 2;
          loop invariant count == \sum(integer ii=0, i-1, 
                                       \sum(integer jj=ii+1, length-1, 
                                            (arr[ii] != arr[jj] ? 1 : 0)));
          loop assigns i, count;
          loop variant length - i;
        */
        for (int i = 0; i < length - 1; i++) {
            /*@ 
              loop invariant i + 1 <= j <= length;
              loop invariant \valid_read(arr + (0 .. length - 1));
              loop invariant 0 <= count <= (length * (length - 1)) / 2;
              loop invariant count == \sum(integer ii=0, i-1, 
                                           \sum(integer jj=ii+1, length-1, 
                                                (arr[ii] != arr[jj] ? 1 : 0)))
                                   + \sum(integer jj=i+1, j-1, 
                                          (arr[i] != arr[jj] ? 1 : 0));
              loop assigns j, count;
              loop variant length - j;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
        }
        return count;
}
