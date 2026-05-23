/**
 * This class contains a method with JML annotations for verification.
 */
public class SVCOMP_linear_0232__307 {

    //@ public invariant i >= 0 && j >= 0 && k >= 0 && l >= 0;

    // Declare the variables as fields of the class
    //@ spec_public
    private int i, j, k, l;

    /**
     * A method with JML specifications.
     * @param n an integer input
     */
    //@ requires n >= 0; // Precondition: n must be non-negative
    //@ ensures i >= 0 && j >= 0 && k >= 0 && l >= 0; // Postcondition: variables remain non-negative
    public void foo307(int n) {
        i = 0;
        j = 0;
        k = 0;
        l = 0;

        //@ maintaining i >= 0 && j >= 0 && k >= 0 && l >= 0;
        //@ decreasing n;
        while (n > 0) {
            i++;
            j++;
            k++;
            l++;
            n--;
        }

        //@ assert i >= 0 && j >= 0 && k >= 0 && l >= 0; // Final assertion
    }
}