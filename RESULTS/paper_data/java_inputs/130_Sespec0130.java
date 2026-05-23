class Sespec0130 {
    static int foo130(int search, int[] array) {
        int location = -1;
        int c;
        for (c = 0; c < array.length; c++) {
            if (array[c] == search) {
                location = c;
                break;
            }
        }
        if (c == array.length) {
            location = -1;
        }
        return location;
    }
}
