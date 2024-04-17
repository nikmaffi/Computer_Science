#include <stdio.h>
#include <list.h>

int main() {
    struct List *l = newl(sizeof(int));
    int num = 0;

    for(int k = 1; k <= 10; k++) {
        appendl(l, &k);
    }

    while(popl(l, &num) != LIST_EMPTY) {
        printf("%d ", num);
    }

    freel(l);

    return 0;
}