public class AverageEven {

    //@ requires size > 0;
    //@ ensures (\num_of int i; 1 < i && i < size && i % 2 == 0; true) > 0 ==>   
    //@         \result == (\sum int i; 1 <= i && i <= size && i % 2 == 0; i) / 
    //@                     (\num_of int i; 1 <= i && i <= size && i % 2 == 0; true);
    //@ ensures (\num_of int i; 1 <= i && i <= size && i % 2 == 0; true) == 0 ==> \result == 0;
    public static int averageEven(int size) {
        int sum = 0;
        int count = 0;

        //@ maintaining 1 <= i && i <= size + 1;
 
 
        //@ decreases size - i + 1;
        for (int i = 1; i <= size; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }

        // Handle the case where there are no even numbers
        if (count == 0) {
            return 0;
        }

        return sum / count;
    }
}
