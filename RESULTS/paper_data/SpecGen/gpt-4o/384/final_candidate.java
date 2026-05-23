/**
    * Computes the binomial coefficient C(n, k) = n! / (k! * (n - k)!).
    *
    * @param n the total number of items.
    * @param k the number of items to choose.
    * @return the binomial coefficient C(n, k).
    * @requires n >= 0 && k >= 0 && k <= n; // Preconditions: n and k must be non-negative, and k <= n.
    * @ensures \result >= 1; // Postcondition: The result is a positive integer.
    */