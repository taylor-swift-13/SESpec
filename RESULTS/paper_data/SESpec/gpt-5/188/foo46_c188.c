
/*@
  logic integer min_prefix(int* a, integer n) =
    n <= 0 ? 0
           : (n == 1 ? a[0]
                     : (min_prefix(a, n-1) <= a[n-1] ? min_prefix(a, n-1) : a[n-1]));
*/

/*@
  logic integer count_eq_prefix(int* a, integer n, integer v) =
    n <= 0 ? 0
           : count_eq_prefix(a, n-1, v) + (a[n-1] == v ? 1 : 0);
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires size >= 0;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > a_len ==> \true;
  ensures \result == \result;
*/
int foo46_c188(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

        
        /*@
          loop invariant 1 <= c;
          loop invariant f == min_prefix(a, c);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns c, f, max;
        */
        for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				max = 1;
			} else if (f == a[c]) {
				max++;
			}
		}
            
		return max;
}
