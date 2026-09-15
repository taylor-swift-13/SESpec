int foo35(int input);


/*@
  assigns \nothing;
  ensures \result == (((( ( (char)(input * 2 + 1) ) | 2) & 3) == 3) ? 1 : 0);
  ensures 0 <= \result && \result <= 1;
  ensures (((((char)(input * 2 + 1)) | 2) & 3) == 3) ==> \result == 1;
  ensures (((((char)(input * 2 + 1)) | 2) & 3) != 3) ==> \result == 0;
*/
int foo35(int input) {
    char c = (char)(input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}