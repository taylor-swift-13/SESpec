/*@
  requires n > 0;
*/
int hoo35(int n) {
       
    int guess;      
    int prev_guess; 
    guess = n / 2;  
    prev_guess = 0; 

    /*@
    loop invariant prev_guess ? guess - prev_guess : prev_guess - guess < guess;
    loop invariant guess > 0 && prev_guess >= 0;
    loop invariant guess * guess >= n || guess * guess <= n;
    loop assigns prev_guess;
    loop assigns guess;
    /*@;
    */
    while (guess != prev_guess) {
        prev_guess = guess;
        guess = (guess + n / guess) / 2;  
    }
    
    /*@ assert guess * guess <= n; */
}