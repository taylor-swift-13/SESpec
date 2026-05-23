int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

/*@ predicate sorted{L}(int *a, integer n) =
      \forall integer i,j; 0 <= i <= j < n ==> a[i] <= a[j];

    predicate equal_arrays{L}(int *a, int *b, integer n) =
      \forall integer i; 0 <= i < n ==> a[i] == b[i];

    predicate shifted_eq_longer_shorter{L}(int *longer, integer ln, int *shorter, integer sn, integer k) =
      sn + 1 == ln &&
      0 <= k <= sn &&
      (\forall integer i; 0 <= i < k ==> longer[i] == shorter[i]) &&
      (\forall integer i; k <= i < sn ==> longer[i+1] == shorter[i]);
*/

/*@ requires args_len >= 0;
    requires arr_len >= 0;

    requires (args_len == 0) || (args != \null);
    requires (arr_len == 0)  || (arr  != \null);

    requires \valid_read(args + (0 .. args_len-1));
    requires \valid_read(arr  + (0 .. arr_len-1));

    requires \separated(args + (0 .. args_len-1), arr + (0 .. arr_len-1));

    assigns \nothing;

    ensures 0 <= \result <= ((args_len > arr_len) ? args_len : arr_len);

    behavior identical:
      assumes args_len == arr_len;
      assumes equal_arrays(args, arr, args_len);
      ensures \result == arr_len;

    behavior extra_in_arr:
      assumes arr_len == args_len + 1;
      assumes \exists integer k; shifted_eq_longer_shorter(arr, arr_len, args, args_len, k);
      ensures \exists integer k; shifted_eq_longer_shorter(arr, arr_len, args, args_len, k) && \result == k;

    behavior extra_in_args:
      assumes args_len == arr_len + 1;
      assumes \exists integer k; shifted_eq_longer_shorter(args, args_len, arr, arr_len, k);
      ensures \exists integer k; shifted_eq_longer_shorter(args, args_len, arr, arr_len, k) && \result == k;

    complete behaviors;
    disjoint behaviors;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		/*@ loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= r <= arr_len;
		    loop invariant \at(ret,LoopEntry) <= ret;
		    loop invariant \at(r,LoopEntry) <= r;
		    loop assigns ret, r;
		    loop variant (args_len - ret) + (arr_len - r);
		*/
		while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
		return ret < args_len ? ret : r;
}
