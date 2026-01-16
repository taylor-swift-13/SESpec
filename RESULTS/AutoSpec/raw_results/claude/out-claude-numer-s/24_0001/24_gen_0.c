/*@
  requires n > 0;
*/
int hoo24(int n,int guess,int prev_guess) {


    guess = n / 2;  
    prev_guess = 0; 

    /*@
    loop invariant prev_guess >= 0 && guess >= 0;
    loop invariant guess * guess >= n || prev_guess * prev_guess >= n || guess == prev_guess;
    loop invariant prev_guess != guess ==> 
                  (prev_guess * prev_guess > n || guess * guess < n);
    loop assigns prev_guess, guess;
    loop variant n - guess;
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert guess * guess <= n; */
}