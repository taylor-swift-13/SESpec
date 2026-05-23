/*@ 
    requires size > 1;
    ensures \result >= 2;
    assigns \nothing;
*/
int averageEven(int size);

#include <stddef.h>

int averageEven(int size) {

		int result = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant result >= 0;
		    loop invariant total >= 0;
		    loop invariant total == 0 ==> result == 0;
		    loop assigns c, result, total;
		    loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}
