int starts_with_te(const char *s);
int f(const char **args, int args_len);

int starts_with_te(const char *s) {
    return s[0] == 't' && s[1] == 'e';
}

int f(const char **args, int args_len) {
    if (args_len < 4) return 0;
    int i = 0;
    for (int j = 0; j < 4; j++) {
        if (starts_with_te(args[j])) ++i;
    }
    return i == 1;
}
