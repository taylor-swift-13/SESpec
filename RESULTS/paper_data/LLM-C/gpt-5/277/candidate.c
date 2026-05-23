/*@ 
  logic integer min_range(int *a, integer l, integer r) =
    l == r ? a[l] :
    (let m = min_range(a, l, r-1) in (m < a[r] ? m : a[r]));

  logic integer running_min_before(int *a, integer j) = min_range(a, 0, j-1);

  logic boolean triggered(int *a, integer j) = a[j] > running_min_before(a, j);

  logic integer max2(integer x, integer y) = x > y ? x : y;

  logic integer max_triggered_min_or_zero_upto(int *a, integer j) =
    j <= 1 ? 0 :
    max2(max_triggered_min_or_zero_upto(a, j-1),
         triggered(a, j-1) ? running_min_before(a, j-1) : 0);

  logic integer max_triggered_min_or_zero(int *a, integer n) = max_triggered_min_or_zero_upto(a, n);
*/

int getGcd(int * arg, int arg_len);

/*@ 
  requires arg_len >= 1;
  requires \valid_read(arg + (0..arg_len-1));
  assigns \nothing;
  ensures \result == max_triggered_min_or_zero(arg, arg_len);
  ensures \result >= 0;
*/
int getGcd(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		/*@
		  loop invariant 1 <= j <= arg_len;
		  loop invariant ret == min_range(arg, 0, j-1);
		  loop invariant g == max_triggered_min_or_zero_upto(arg, j);
		  loop assigns j, g, ret;
		  loop variant arg_len - j;
		*/
		for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}
