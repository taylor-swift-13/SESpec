class Sespec0025 {
    /*@ spec_public @*/ enum enum1 { VAL5 }

    //@ ensures true;
    static void foo25(String[] args) {
        enum1 e = enum1.VAL5;
        assert e == enum1.VAL5;
    }
}