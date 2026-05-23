class Sespec0026 {
    //@ assignable \nothing;
    //@ ensures args == \old(args) && args_len == \old(args_len);
    static void foo26(String[] args, int args_len) {
        float f = 2.5f;
        assert f == 2.5f;
        assert f < 3.0f;
        assert f > 2.0f;
        double d = 2.5;
        assert d == 2.5;
        assert d < 3.0;
        assert d > 2.0;
    }
}