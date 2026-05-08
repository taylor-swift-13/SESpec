short foo42_helper1(short num);
int foo42_helper2(int num);
long long foo42(long long num);

short foo42_helper1(short num) {

		if (0 <= num)
			return num;
		else
			return (short)-num;
}

int foo42_helper2(int num) {

		if (0 <= num)
			return num;
		else
			return -num;
}

long long foo42(long long num) {

		if (0 <= num)
			return num;
		else
			return -num;
}
