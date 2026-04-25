#include <string.h>

int foo49(const char * jewels, const char * stones);

int foo49(const char * jewels, const char * stones) {

        int jewelsCount = 0;
        int jewelsLength = ((int)strlen(jewels)), stonesLength = ((int)strlen(stones));
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i);
            for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j);
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
}
