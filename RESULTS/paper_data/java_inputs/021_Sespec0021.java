class Sespec0021 {
    static int starts_with_te(char[] s) {
        return (s[0] == 't' && s[1] == 'e') ? 1 : 0;
    }

    static int foo21(char[][] args) {
        if (args.length < 4) return 0;
        int i = 0;
        for (int j = 0; j < 4; j++) {
            if (starts_with_te(args[j]) != 0) ++i;
        }
        return (i == 1) ? 1 : 0;
    }
}
