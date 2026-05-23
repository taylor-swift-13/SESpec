/*@ predicate valid_read_array(int *a, integer n) =
      n == 0 || \valid_read(a + (0 .. n - 1));

    predicate nondecreasing{L}(int *a, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> \at(a[i],L) <= \at(a[j],L);

    predicate equal_prefix{L}(int *a, int *b, integer n) =
      \forall integer i; 0 <= i < n ==> \at(a[i],L) == \at(b[i],L);

    predicate is_remove_at{L}(int *src, integer nsrc, int *dst, integer k) =
      0 <= k < nsrc &&
      \forall integer i; 0 <= i < k ==> \at(src[i],L) == \at(dst[i],L) &&
      \forall integer i; k <= i < nsrc - 1 ==> \at(src[i+1],L) == \at(dst[i],L);
*/

int findExtra(int * args, int args_len, int * arr, int arr_len, int Array);

/*@ 
  requires args_len >= 0;
  requires arr_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
  requires \separated(args + (0 .. args_len - 1), arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= (args_len < arr_len ? arr_len : args_len);

  behavior equal_arrays:
    assumes args_len == arr_len;
    assumes equal_prefix{Pre}(args, arr, args_len);
    ensures \result == args_len;

  behavior extra_in_args:
    assumes args_len == arr_len + 1;
    assumes nondecreasing{Pre}(args, args_len);
    assumes nondecreasing{Pre}(arr, arr_len);
    assumes \exists integer k; is_remove_at{Pre}(args, args_len, arr, k);
    ensures is_remove_at{Pre}(args, args_len, arr, \result);

  behavior extra_in_arr:
    assumes arr_len == args_len + 1;
    assumes nondecreasing{Pre}(args, args_len);
    assumes nondecreasing{Pre}(arr, arr_len);
    assumes \exists integer k; is_remove_at{Pre}(arr, arr_len, args, k);
    ensures is_remove_at{Pre}(arr, arr_len, args, \result);
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		/*@
		  loop invariant 0 <= ret <= args_len;
		  loop invariant 0 <= len <= arr_len;
		  loop assigns ret, len;
		  loop variant args_len + arr_len - (ret + len);
		*/
		while (ret < args_len && len < arr_len) {
			if (args[ret] < arr[len]) {
				ret++;
			} else if (args[ret] > arr[len]) {
				len++;
			} else {
				ret++;
				len++;
			}
		}
		return ret < args_len ? ret : len;
}
