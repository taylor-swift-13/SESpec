int foo54_helper1_c28(const char **args, int args_len);
void foo28(const char **args, int args_len);

int foo54_helper1_c28(const char **args, int args_len);
void foo28(const char **args, int args_len);


/*@
 requires \valid(args) ;
ensures (args != 0) && (**args == \old(**args)) ==> (\result == 1);
ensures (args == 0) && (**args == \old(**args)) ==> (\result == 0);

assigns \nothing;
*/

int foo54_helper1_c28(const char **args, int args_len) 
{
    return args != 0;
}


void foo28(const char **args, int args_len) {
    foo54_helper1_c28(args, args_len);
}