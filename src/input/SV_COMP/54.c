int foo54_helper1(const char * * args, int args_len);
void foo54(const char * * args, int args_len);

int foo54_helper1(const char * * args, int args_len) {

    return args != 0;
}

void foo54(const char * * args, int args_len) {

    foo54_helper1(args, args_len);
}
