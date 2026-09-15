/*@
    requires x_len >= 0;
    requires x_len == 0 || \valid_read(x + (0 .. x_len - 1));
    assigns \nothing;
    ensures x_len == 0 ==> \result == -1;
    ensures x_len > 0 ==> (-1 <= \result < x_len);
    ensures \result >= 0 ==> x[\result] == 0;
    ensures \result == -1 ==> \forall integer i; 0 <= i < x_len ==> x[i] != 0;
*/
int FindFirstZero(int * x, int x_len);

int FindFirstZero(int * x, int x_len) {

/*@ 
    loop invariant 0 <= index <= x_len;
    loop invariant \forall integer i; 0 <= i < index ==> x[i] != 0;
    loop assigns index;
    loop variant x_len - index;
*/
         	assert x_len >= 0;
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}
