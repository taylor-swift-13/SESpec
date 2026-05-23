int foo39_c35(int input);


/*@
  assigns \nothing;
*/
int foo39_c35(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}