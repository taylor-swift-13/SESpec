
/*@
  requires \at(size,Pre) != 0 && \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  assigns \nothing;
  ensures \result == 0 || \result >= 1;
  ensures size == \old(size);
  ensures a == \old(a);
  ensures a_len == \old(a_len);
  ensures size == 0 ==> \result == 0;
  ensures size != 0 ==> \result >= 1;
*/
int foo186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

        /*@
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant total >= 1;
          loop invariant f <= a[0];
          loop invariant c < \at(size,Pre) ==> total >= 1;
          loop invariant c < \at(size,Pre) ==> f <= a[0];
          loop invariant c < \at(size,Pre) ==> total == 1 || total > 1;
          loop invariant !(c < \at(size,Pre)) ==> total >= 1;
          loop assigns c, f, total;
            */
            for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				total = 1;
			} else if (f == a[c]) {
				total++;
			}
		}
            
		return total;
}
