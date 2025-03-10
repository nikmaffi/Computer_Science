#include <quick_sort.h>

#include <stdint.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}

unsigned partition(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *)) {
    void *p = malloc(size); memcpy(p, buffer, size);
    unsigned i = 1, j = n - 1;

    while(i <= j) {
        if(cmp((uint8_t *)buffer + i * size, p) <= 0) {
            i++;
            continue;
        }
        
        if(cmp((uint8_t *)buffer + j * size, p) > 0) {
            j--;
            continue;
        }

        swap((uint8_t *)buffer + i * size, (uint8_t *)buffer + j * size, size);
        i++;
        j--;
    }

    swap(buffer, (uint8_t *)buffer + j * size, size);

    free(p);

    return j;
}

void quick_sort(void *buffer, unsigned n, size_t size, int (*cmp)(const void *, const void *)) {
    unsigned p = 0;

    if(n <= 1) {
        return;
    }

    p = partition(buffer, n, size, cmp);
    quick_sort(buffer, p, size, cmp);
    quick_sort((uint8_t *)buffer + (p + 1) * size, n - p - 1, size, cmp);
}