const char * countDivisors(int num);

/*@ 
  requires num >= 1;
  requires num < 2147483647;
  assigns \nothing;
  ensures \result == "Even" || \result == "Odd";
  ensures (\result == "Odd") <==> (\exists integer k; 1 <= k && k * k == num);
  ensures (\result == "Even") <==> (\forall integer k; 1 <= k ==> k * k != num);
  ensures (\result == "Even") <==> ((\numof integer d; 1 <= d <= num && num % d == 0) % 2 == 0);
  ensures (\result == "Odd") <==> ((\numof integer d; 1 <= d <= num && num % d == 0) % 2 == 1);
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		  loop invariant 1 <= c <= num + 1;
		  loop invariant 0 <= result <= c - 1;
		  loop invariant result == \numof integer d; 1 <= d <= c - 1 && num % d == 0;
		  loop assigns c, result;
		  loop variant num - c + 1;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		//@ assert result == \numof integer d; 1 <= d <= num && num % d == 0;
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
