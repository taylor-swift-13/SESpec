const char * checkTypeOfTriangle(int a, int b, int c);

const char * checkTypeOfTriangle(int a, int b, int c) {

        if (a + b > c && a + c > b && b + c > a)
            return "Acute-angled Triangle";
        if (a == b && b == c)
            return "Equilateral Triangle";
        if (a != b && a != c && b != c)
            return "Obtuse-angled Triangle";
        if (a == b || a == c || b == c)
            return "Right-angled Triangle";
        return "Scalene Triangle";
}
