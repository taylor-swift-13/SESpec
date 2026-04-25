const char * foo220(int length, int n, int d);

const char * foo220(int length, int n, int d) {

		if (length + n > d && length + d > n
				&& n + d > length)
			return "Acute-angled Triangle";
		if (length == n && n == d)
			return "Equilateral Triangle";
		if (length != n && length != d && n != d)
			return "Obtuse-angled Triangle";
		if (length == n || length == d || n == d)
			return "Right-angled Triangle";
		return "Scalene Triangle";
}
