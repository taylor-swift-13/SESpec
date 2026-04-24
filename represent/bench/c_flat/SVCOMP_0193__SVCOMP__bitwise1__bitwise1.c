int fun(int input);

int fun(int input) {

    c = (char) (input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
}
