#include <stdio.h>
#include <stdlib.h>

struct anu {
    int data;
    struct anu* add;
};

int main() {
    int n, i;
    struct anu *y, *head;

    printf("Number of nodes you want: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (i == 0) {
            y = (struct anu*)malloc(sizeof(struct anu));
            printf("Enter data for node %d: ", i + 1);
            scanf("%d", &y->data);
            y->add = NULL;
            head = y;
        } else {
            y->add = (struct anu*)malloc(sizeof(struct anu));
            y = y->add;
            printf("Enter data for node %d: ", i + 1);
            scanf("%d", &y->data);
            y->add = NULL;
        }
    }

    printf("THE LINKED LIST IS: ");
    y = head;

    while (y != NULL) {
        printf("%d -> ", y->data);
        y = y->add;
    }

    printf("NULL\n");

    y = head;
    while (y != NULL) {
        struct anu* temp = y;
        y = y->add;
        free(temp);
    }

    return 0;
}
