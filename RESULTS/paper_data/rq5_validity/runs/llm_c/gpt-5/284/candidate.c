int getGcd(int * arr, int arr_len);

/*@ logic integer lmin(integer x, integer y) = x <= y ? x : y; */
/*@ logic integer lmax(integer x, integer y) = x >= y ? x : y; */

/*@ logic integer prefix_min{L}(int *a, integer j) =
      j == 0 ? \at(a[0], L) : lmin(prefix_min(a, j-1), \at(a[j], L)); */

/*@ logic integer maxres{L}(int *a, integer n) =
      n <= 1 ? 0 :
      lmax( maxres(a, n-1),
            ((\at(a[n-1], L) > prefix_min(a, n-2)) ? prefix_min(a, n-2) : 0)); */

/*@ requires arr_len >= 1;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result == maxres{Pre}(arr, arr_len);
*/
int getGcd(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        /*@ 
          loop invariant 1 <= i <= arr_len;
          loop invariant min == prefix_min{Pre}(arr, i-1);
          loop invariant result == maxres{Pre}(arr, i);
          loop assigns i, result, min;
          loop variant arr_len - i;
        */
        for (int i = 1; i < arr_len; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
}
