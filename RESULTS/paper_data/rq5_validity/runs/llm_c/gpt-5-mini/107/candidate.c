int FindFirstZero(int * x, int x_len);

/*@
    requires x_len >= 0;
    requires x_len == 0 || \valid(x + (0 .. x_len - 1));
    assigns \nothing;
    ensures -1 <= \result < x_len;
    ensures \result == -1 ==> \forall integer j; 0 <= j < x_len ==> x[j] != 0;
    ensures 0 <= \result < x_len ==> x[\result] == 0;
    ensures 0 <= \result < x_len ==> \forall integer j; 0 <= j < \result ==> x[j] != 0;
*/
int FindFirstZero(int * x, int x_len) {

         	assert x_len >= 0;
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		/*@
            		    loop invariant 0 <= index <= x_len;
            		    loop invariant \forall integer j; 0 <= j < index ==> x[j] != 0;
            		    loop assigns index;
            		    loop variant x_len - index;
            		*/
            		while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}
