#include <stdlib.h>

/*@
    requires c >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int c);

 /*@
    requires c >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
		/*@
            loop invariant 1 <= cat <= c + 1;
            loop assigns cat, arr[0..c];
            loop variant c - cat + 1;
        */
		for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			/*@
                loop invariant 0 <= n <= cat;
                loop invariant arr[cat] >= 0;
                loop assigns n, arr[cat];
                loop variant cat - n;
            */
			for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
		}
		return arr[c];
}
