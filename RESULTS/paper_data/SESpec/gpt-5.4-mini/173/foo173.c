
/*@
  requires p >= 0;
  requires Array >= 0;
  requires n >= p;
  requires arr1_len >= 0;
  requires arr_len >= 0;
  requires Array <= arr1_len;
  requires n <= arr_len;
  requires \valid_read(arr1 + (0 .. arr1_len - 1));
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures p == 0 ==> \result == -1;
  ensures p > 0 ==> (\result == -1 || (\exists integer i; 0 <= i < arr1_len && \result == arr1[i]) || (\exists integer j; 0 <= j < arr_len && \result == arr[j]));
  ensures \result == -1 ==> p == 0 || p > 0;
*/
int foo173(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		
            
        /*@
          loop invariant 0 <= count <= p;
          loop invariant 0 <= result <= Array;
          loop invariant 0 <= tmp;
          loop invariant result + tmp == count;
          loop invariant tmp <= count;
          loop invariant (count < p) ==> (result <= Array);
          loop invariant (count < p) ==> (tmp <= n);
          loop invariant (count < \at(p,Pre)) ==> (result <= \at(Array,Pre) && tmp <= \at(n,Pre));
          loop invariant (count < \at(p,Pre)) ==> (result + tmp == count);
          loop invariant (count < \at(p,Pre)) ==> (0 <= result && 0 <= tmp);
          loop invariant (count < \at(p,Pre)) ==> (arr1_len == \at(arr1_len,Pre) && arr_len == \at(arr_len,Pre));
          loop invariant (count < \at(p,Pre)) ==> (arr1 == \at(arr1,Pre) && arr == \at(arr,Pre));
          loop invariant (count < \at(p,Pre)) ==> (n == \at(n,Pre) && p == \at(p,Pre) && Array == \at(Array,Pre));
          loop invariant (count < \at(p,Pre)) ==> (result <= count && tmp <= count);
          loop invariant (count < \at(p,Pre)) ==> (result == 0 || tmp == 0 || result + tmp > 0);
          loop invariant (count < \at(p,Pre)) ==> (result < Array || tmp < n || result + tmp == count);
          loop invariant (!(count < \at(p,Pre))) ==> ((tmp == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
          loop invariant \forall integer i; 0 <= i < arr1_len ==> arr1[i] == \at(arr1[i],Pre);
          loop assigns count, result, tmp;
            */
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
