class Sespec0123 {
    static int foo123(String pat, String txt) {
        int i = 0;
        while (i < ((int) pat.length())) {
            if (i >= ((int) txt.length()) || pat.charAt(i) != txt.charAt(i))
                return 0;
            i = i + 1;
        }
        return 1;
    }
}
