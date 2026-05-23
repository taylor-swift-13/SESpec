class PrimeCheck {

	/*@ 
 
	  @ ensures !\result <==> (\exists int j; 2 - 1 <= j && j - 1 <= a/2; a % j == 0);  
	  @*/
	public boolean isPrime(int a) {
		int i = 2;
		int mid = a/2;

		//@ maintaining mid == a/2;
		//@ maintaining i >= 2;
		//@ maintaining (\forall int j; 2 <= j && j < i && j <= mid; a % j != 0);
		//@ decreases mid - i + 1;
		while (i <= mid) {
			if (a%i == 0)
				return false;
			i++;
		}
		return true;
	}
}
