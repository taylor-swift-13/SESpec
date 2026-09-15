/*@ 
    requires \valid_read(args + (0 .. args_len-1)) || args == \null;
    ensures \result == (args != \null);
    assigns \nothing;
*/
int f(const char **args, int args_len);

/*@ 
    requires \valid_read(args + (0 .. args_len-1)) || args == \null;
    assigns \nothing;
*/
void main(const char **args, int args_len);

int f(const char **args, int args_len) {
    return args != 0;
}

void main(const char **args, int args_len) {
    f(args, args_len);
}