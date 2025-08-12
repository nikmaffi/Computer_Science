#include <stdio.h>

#include <list.h>

int main() {
    struct list *l = new_list(sizeof(int));
	int *p = NULL;
	int num = 0;

    for(int k = 1; k <= 10; k++) {
        append_list(l, &k);
    }

	while((p = (int *)get_list(l, num++)) != NULL) {
		printf("%d ", *p);
	}
	puts("");

    free_list(l);

    return 0;
}
