
/*@ logic integer count_gt(int* a, integer x, integer lo, integer hi) =
      lo >= hi ? 0 :
      count_gt(a, x, lo, hi - 1) + (a[hi - 1] > x ? 1 : 0);
*/

/*@ logic integer invcount_upto(int* a, integer i, integer n) =
      i >= n ? 0 :
      count_gt(a, a[i], i + 1, n) + invcount_upto(a, i + 1, n);
*/

/*@
  requires \valid(&indices[0] + (0..indices_len-1));
  requires 0 <= num <= indices_len;
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
*/
int foo247(int * indices, int indices_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index && index <= num;
          loop invariant 0 <= ret;
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre);
          loop invariant \forall integer k; 0 <= k < index ==> 0 <= indices[k] <= 100;
          loop invariant \forall integer i, j; 0 <= i < j < index ==> indices[i] <= indices[j] || indices[i] > indices[j];
          loop assigns index, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index && index < num;
          loop invariant index + 1 <= c && c <= num;
          loop invariant ret >= 0;
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre);
          loop invariant \forall integer k; 0 <= k < indices_len ==> 0 <= indices[k] <= 100;
          loop assigns c, ret;
            */
            for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
