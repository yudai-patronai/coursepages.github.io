#include <stdio.h>
#include <stdlib.h>
#define pr() fprintf(stderr, "%d : %s\n",
typedef int Data;
struct Node {
    Data val;
    struct Node *next;
};
void list_add_first_qazwsx(struct Node **list, Data x); // чтобы не совпали названия, вдруг кто захочет написать сам такую функцию
void list_print(struct Node *s);
void list_destroy(struct Node **s);
void list_sort(struct Node **list);
void list_add_first_qazwsx(struct Node **list, Data x)
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->val = x;
    node->next = *list;
    *list = node;
}

void list_print(struct Node *s)
{
    if (NULL == s) {
        printf("Empty list\n");
        return;
    }
    struct Node *p;
    for (p = s; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}

void list_destroy(struct Node **list)
{
    struct Node *p, *next;
    for (p = *list; p != NULL; p = next) {
        next = p->next;
        free(p);
    }
    *list = NULL;
}

int main()
{
    struct Node *list = NULL;
    int x;
    while (1 == scanf("%d", &x))
        list_add_first_qazwsx(&list, x);

    // list_print(list);
    list_sort(&list);
    list_print(list);
    list_destroy(&list);
    return 0;
}

#line 100000

