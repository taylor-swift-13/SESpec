public class Fibonacci {

	//@ ensures n < 0 ==> \result == -1;
	//@ ensures n == 0 ==> \result == 0;
	//@ ensures n > 0 ==> \result >= 0;
	public static int fibCompute(int n) {
		if(n < 0) return -1;
		else if(n == 0) return 0;

		int[] fib = new int[n + 1];
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		//@ maintaining fib.length == n + 1;
		//@ maintaining 2 <= index && index <= fib.length;
		//@ maintaining fib[0] == 0 && fib[1] == 1;
		//@ maintaining fib[index - 1] >= 0 && fib[index - 2] >= 0;
		//@ decreases fib.length - index;
		while (index < fib.length) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
	}

}