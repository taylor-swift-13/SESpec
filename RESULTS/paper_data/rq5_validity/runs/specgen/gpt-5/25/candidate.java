class Sespec0025 {
    enum enum1 { VAL5 }

    static void foo25(String[] args) {
        enum1 e = enum1.VAL5;
        assert e == enum1.VAL5;
    }
}
