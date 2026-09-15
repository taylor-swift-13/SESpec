/*@
  requires -1073741824 <= input <= 1073741823;
  assigns \nothing;
  ensures \result == 1;
*/
int fun(int input);

int fun(int input) {
    char c = (char)(input * 2 + 1);
    //@ assert (((int)c) & 1) == 1;
    int i = (c | 2);
    //@ assert (i & 2) == 2;
    //@ assert ((i & 3) == 3);
    return (i & 3) == 3;
}
