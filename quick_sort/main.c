#include <stdio.h>
#include <time.h>

#include <quick_sort.h>

#define MAX_SIZE 20
#define RAND_RANGE 100

void print_array(int *array, unsigned n) {
    printf("[ ");
    for(int *e = array; e < array + n; e++) {
        printf("%2d ", *e);
    }
    printf("]\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main(void) {
    int *array = NULL;
    int size = 0;

    srand(time(NULL));

    size = rand() % MAX_SIZE + 1;
    array = (int *)malloc(sizeof(int) * size);

    for(int k = 0; k < size; k++) {
        array[k] = rand() % RAND_RANGE;
    }

    print_array(array, size);
    quick_sort(array, size, sizeof(int), compare);
    print_array(array, size);

    free(array);

    return EXIT_SUCCESS;
}