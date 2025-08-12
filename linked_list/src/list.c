#include <list.h>

#include <stdlib.h>
#include <string.h>

struct list *new_list(size_t size) {
	struct list *l = (struct list *)malloc(sizeof(struct list));

	l->size = size;
	l->head = NULL;

	return l;
}

int append_list(struct list *l, const void *data) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	struct node *tmp = NULL;

	if(!new) {
		return LIST_MALLOC_FAILED;
	}

	new->data = malloc(l->size);

	if(!new->data) {
		free(new);
		return LIST_MALLOC_FAILED;
	}

	memcpy(new->data, data, l->size);
	new->next = NULL;

	if(!l->head) {
		l->head = new;
	} else {
		tmp = l->head;

		while(tmp->next) {
			tmp = tmp->next;
		}

		tmp->next = new;
	}

	return LIST_SUCCESS;
}

int append_sort_list(struct list *l, const void *data, int (*compare)(const void *, const void *));
int insert_list(struct list *l, size_t index, const void *data);

void *get_list(struct list *l, size_t index) {
	struct node *tmp = l->head;

	for(size_t k = 0; k < index && tmp; k++, tmp = tmp->next);

	if(!tmp) {
		return NULL;
	}

	return tmp->data;
}

int remove_list(struct list *l, size_t index, void *data);
size_t size_list(struct list *l);

void free_list(struct list *l) {
	struct node *tmp = l->head;

	while(tmp) {
		l->head = l->head->next;

		free(tmp->data);
		free(tmp);

		tmp = l->head;
	}
	
	free(l);
}
