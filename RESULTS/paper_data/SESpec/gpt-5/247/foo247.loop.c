
/*@
  logic integer invcnt(int* a, integer i, integer j) =
    (j <= i + 1) ? 0
                 : invcnt(a, i, j - 1) + (a[i] > a[j - 1] ? 1 : 0);

  logic integer invprefix(int* a, integer n, integer i) =
    (i <= 0) ? 0
             : invprefix(a, n, i - 1) + invcnt(a, i - 1, n);
*/
        
/*@
  requires \valid(&indices[0] + (0..indices_len-1));
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
*/

int foo247(int * indices, int indices_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= ret;
          loop invariant ret == invprefix(indices, num, index);
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre);
          loop assigns index, c, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= c <= num;
          loop invariant c == index + 1 || (index + 1 <= c && c <= num);
          loop invariant ret >= 0;
          loop assigns ret, c;
          loop invariant ret == invprefix(indices, num, index) + invcnt(indices, index, c);
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre);
          loop invariant \forall integer k; index + 1 <= k < c ==> (indices[index] > indices[k] ? \true : \true);
            */
            for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
