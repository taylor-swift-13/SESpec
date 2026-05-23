/*@
    requires \valid_read(a+(0..a_len-1));
    requires \valid_read(b+(0..b_len-1));
    ensures \result == 1 <==> (a_len == b_len && \forall integer i; 0 <= i < a_len ==> a[i] == b[i]);
    ensures \result == 0 <==> (a_len != b_len || \exists integer i; 0 <= i < a_len && a[i] != b[i]);
    assigns \nothing;
*/
int arrcmp(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant \forall integer j; 0 <= j < i ==> a[j] == b[j];
            loop assigns i;
            loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
