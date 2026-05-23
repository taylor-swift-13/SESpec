int pairOrSum(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \result == \sum(integer i, 0, arr_len-1, \sum(integer j, i+1, arr_len-1, arr[i] ^ arr[j]));
*/
int pairOrSum(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@ 
          loop invariant 0 <= i <= arr_len;
          loop invariant sum == \sum(integer p, 0, i-1, \sum(integer q, p+1, arr_len-1, arr[p] ^ arr[q]));
          loop assigns i, j, sum;
          loop variant arr_len - i;
        */
        for (int i = 0; i < arr_len; i++) {
            /*@ 
              loop invariant i + 1 <= j <= arr_len;
              loop invariant sum == \sum(integer p, 0, i-1, \sum(integer q, p+1, arr_len-1, arr[p] ^ arr[q])) 
                                  + \sum(integer q, i+1, j-1, arr[i] ^ arr[q]);
              loop assigns j, sum;
              loop variant arr_len - j;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
}
