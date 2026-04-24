int isPrime(int a);

int isPrime(int a) {

		int i = 2;
		int mid = a/2;

		while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}
