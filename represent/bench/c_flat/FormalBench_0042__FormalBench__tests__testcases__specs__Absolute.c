short Absolute(short num);
int Absolute_2(int num);
long long Absolute_3(long long num);

short Absolute(short num) {

		if (0 <= num)
			return num;
		else
			return (short)-num;
}

int Absolute_2(int num) {

		if (0 <= num)
			return num;
		else
			return -num;
}

long long Absolute_3(long long num) {

		if (0 <= num)
			return num;
		else
			return -num;
}
