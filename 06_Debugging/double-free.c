#include <stdlib.h>

int main() {
    int *a = malloc(sizeof(int));
    free(a);
    free(a);
    return 0;
}