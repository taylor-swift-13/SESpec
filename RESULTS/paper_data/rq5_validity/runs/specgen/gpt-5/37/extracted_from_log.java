class Sespec0037 {
    /*@ spec_public @*/ static int data;

    //@ ensures \result == 1;
    //@ assignable \nothing;
    /*@ spec_public @*/ static int foo57_helper1_c37() {
        return 1;
    }

    //@ ensures \result == 1;
    //@ assignable \nothing;
    /*@ spec_public @*/ static int foo37() {
        return foo57_helper1_c37();
    }
}