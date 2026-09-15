/*@
    requires \valid(x+(0..x_len-1));
    requires x_len >= 0;
    ensures \result == -1 || (0 <= \result < x_len && x[\result] == 0);
    ensures \result == -1 ==> \forall integer i; 0 <= i < x_len ==> x[i] != 0;
    assigns \nothing;
*/
int FindFirstZero(int * x, int x_len);

int FindFirstZero(int * x, int x_len) {

         	assert x_len >= 0;
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		/*@
            		loop invariant 0 <= index <= x_len;
            		loop invariant \forall integer i; 0 <= i < index ==> x[i] != 0;
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
