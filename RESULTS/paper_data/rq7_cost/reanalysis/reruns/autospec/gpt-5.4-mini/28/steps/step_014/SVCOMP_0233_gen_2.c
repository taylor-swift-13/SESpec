/*@ 
    requires \valid_read(args) || args == 0;
    assigns \nothing;
    ensures \result == (args != 0);
*/
int f(const char **args, int args_len);

void main(const char **args, int args_len);

/*@ 
    requires \valid_read(args) || args == 0;
    assigns \nothing;
    ensures \result == (args != 0);
*/
int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}