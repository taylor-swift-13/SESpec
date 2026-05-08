int foo39(int input);

int foo39(int input) {

    char c = (char) (input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}
