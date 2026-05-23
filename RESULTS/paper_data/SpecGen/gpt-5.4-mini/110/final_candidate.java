public class GCD {

	//@ requires true;
	//@ ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
	//@ ensures (\old(num1) == 0 && \old(num2) != 0) ==> \result == (\old(num2) < 0 ? -\old(num2) : \old(num2));
	//@ ensures (\old(num1) != 0 && \old(num2) == 0) ==> \result == (\old(num1) < 0 ? -\old(num1) : \old(num1));
	//@ ensures (\old(num1) != 0 && \old(num2) != 0) ==> \result > 0;
	//@ ensures (\old(num1) != 0 && \old(num2) != 0) ==> (\old(num1) % \result == 0 && \old(num2) % \result == 0);
	public static int gcd(int num1, int num2){
		int result = 1;
	 	num1 = (0 <= num1) ? num1 : -num1;
		num2 = (0 <= num2) ? num2 : -num2;

		if (num1 == 0 && num2 == 0) {
			return -1;
		}

		if (num1 == 0 || num2 == 0) {
			return (num1 > num2) ? num1 : num2;
		}

		//@ maintaining 1 <= i && i <= num1 + 1 && i <= num2 + 1;
		//@ maintaining result >= 1;
		//@ maintaining (\forall int d; 1 < d && d <= i; (num1 % d == 0 && num2 % d == 0) ==> d - 1 <= result);  
		//@ decreases (num1 < num2 ? num1 : num2) - i + 1;
		for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
		return result;
	}
}
