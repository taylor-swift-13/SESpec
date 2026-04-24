class SVCOMP_unlinear_0059__35 {
static int hoo35(int n) {

int guess;
int prev_guess;
guess = n / 2;
prev_guess = 0;

while (guess != prev_guess) {
prev_guess = guess;
guess = (guess + n / guess) / 2;
}

return 0;
}
}
