/*@
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int fun(int input);

int fun(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}
