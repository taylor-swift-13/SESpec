const char * countDivisors(int num);

 /*@
     requires num >= 0;
     assigns \nothing;
     ensures (\result == "Even") <==> (\sum integer i; 1 <= i <= num; (num % i == 0 ? 1 : 0)) % 2 == 0;
     ensures (\result == "Odd")  <==> (\sum integer i; 1 <= i <= num; (num % i == 0 ? 1 : 0)) % 2 == 1;
 */
const char * countDivisors(int num) {

		int result = 0;
		/*@
		    loop invariant 1 <= index <= num + 1;
		    loop invariant 0 <= result <= num;
		    loop invariant result == \sum integer j; 1 <= j <= index-1; (num % j == 0 ? 1 : 0);
		    loop assigns index, result;
		    loop variant num - index + 1;
		*/
		for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
