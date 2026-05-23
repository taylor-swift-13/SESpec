int foo35(int input);


/*@
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result == 1) <==> ( (( (char)(input * 2 + 1) | 2) & 3) == 3 );
  ensures (\result == 0) <==> ( (( (char)(input * 2 + 1) | 2) & 3) != 3 );
*/
int foo35(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}