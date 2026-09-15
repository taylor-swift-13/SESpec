class instanceof1 {

    //@ ensures \result == (args instanceof Object);
    public static boolean f(String[] args) {
        return args instanceof Object;
    }

    //@ requires args != null;
    //@ ensures true; // No specific post-condition for main method
    public static void main(String[] args) {
        f(args);
    }
}