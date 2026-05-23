int foo54_helper1_c28(const char **args, int args_len);
void foo28(const char **args, int args_len);

int foo54_helper1_c28(const char **args, int args_len) {
    return args != 0;
}

void foo28(const char **args, int args_len) {
    foo54_helper1_c28(args, args_len);
}
