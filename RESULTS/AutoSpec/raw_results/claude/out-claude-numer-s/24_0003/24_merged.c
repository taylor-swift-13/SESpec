/*@
  requires n > 0;
*/
int hoo24(int n,int guess,int prev_guess) {


    guess = n / 2;  
    prev_guess = 0; 

    /*@
    loop invariant prev_guess <= guess;
    loop invariant prev_guess * prev_guess <= n;
    loop invariant n <= guess * guess;
    loop invariant 0 <= prev_guess;
    loop assigns prev_guess;
    loop assigns guess;
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert guess * guess <= n; */
}