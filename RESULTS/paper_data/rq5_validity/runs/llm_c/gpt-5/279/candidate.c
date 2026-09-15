/*@ 
  logic integer min_range{L}(int *a, integer l, integer u) =
    (l == u) ? \at(a[u],L)
             : ((l < u) ? ((min_range{L}(a, l+1, u) < \at(a[l],L)) ? min_range{L}(a, l+1, u) : \at(a[l],L))
                        : \at(a[u],L));
*/

int getGcd(int * args, int args_len);

/*@ 
  requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;

  ensures \result >= 0;
  ensures \result <= (\at(args[0],Pre) > 0 ? \at(args[0],Pre) : 0);

  ensures \result == 0 || (\exists integer k; 0 <= k < args_len && \result == \at(args[k],Pre));

  ensures (\forall integer j; 1 <= j < args_len ==> 
            (\at(args[j],Pre) > min_range{Pre}(args, 0, j-1) ==> 
               \result >= min_range{Pre}(args, 0, j-1)));

  ensures ((\forall integer j; 1 <= j < args_len ==> \at(args[j],Pre) <= min_range{Pre}(args, 0, j-1)) ==> \result == 0);
*/
int getGcd(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		/*@
		  loop invariant 1 <= j <= args_len;
		  loop invariant (\forall integer i; 0 <= i < j ==> ret <= \at(args[i],Pre));
		  loop invariant (\exists integer i; 0 <= i < j && ret == \at(args[i],Pre));
		  loop invariant g >= 0;
		  loop invariant g <= (\at(args[0],Pre) > 0 ? \at(args[0],Pre) : 0);
		  loop invariant (\forall integer k; 1 <= k < j && \at(args[k],Pre) > min_range{Pre}(args, 0, k-1) ==> 
		                               g >= min_range{Pre}(args, 0, k-1));
		  loop invariant (g == 0 || (\exists integer k; 1 <= k < j && \at(args[k],Pre) > min_range{Pre}(args, 0, k-1) && 
		                                        g == min_range{Pre}(args, 0, k-1)));
		  loop assigns j, g, ret;
		  loop variant args_len - j;
		*/
		for (int j = 1; j < args_len; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
		return g;
}
