/*@
    requires indices_len >= 0;
    requires num >= 0;
    requires \valid_read(indices + (0 .. indices_len - 1));
    requires num <= indices_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * indices, int indices_len, int num);

 /*@
    requires indices_len >= 0;
    requires num >= 0;
    requires \valid_read(indices + (0 .. indices_len - 1));
    requires num <= indices_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * indices, int indices_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop assigns index, ret, c;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= c <= num;
			    loop invariant ret >= 0;
			    loop assigns c, ret;
			    loop variant num - c;
			*/
			for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}
