class SVCOMP_linear_0225__300 {
    /*@ 
      @ // no specific precondition
      @ requires true;
      @ // method does not modify any visible state
      @ assignable \nothing;
      @ // a trivial postcondition (locals are not available here)
      @ ensures true;
      @*/
    static void foo300(int n) {

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

    /*@ 
      @ // loop invariants about the local counters
      @ maintaining i >= 0 && j >= 0 && k >= 0;
      @ maintaining i % 3 == 0 && j % 3 == 0 && k % 3 == 0;
      @ maintaining j + k == i;
      @ // measure that strictly decreases on each iteration
      @ decreases n - i;
      @*/
    while(i < n){
    i = i + 3;
    if((i % 2) != 0)
    j = j + 3;
    else
    k = k + 3;
    }

    }
    }