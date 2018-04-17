#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

void test(int argc, char *argv[])
{
    NODE *root = NULL;

    for (int i=1; i<argc; i++)
    {
        int *t = calloc(1, sizeof(int));
        *t = atoi(argv[i]);
        insert_avl(&root, NULL, t);
        #ifdef DEBUG
        inorder(root);
        printf("height: %d\n", get_height(root));
        printf("------------------\n");
        #endif
    }

    inorder(root);
    printf("------------------\n");

    for (int i=1; i<argc; i++)
    {
        printf("deleting... %s \n", argv[i]);
        int *t = calloc(1, sizeof(int));
        *t = atoi(argv[i]);
        delete_avl(&root, t);
        free(t);
        #ifdef DEBUG
        inorder(root);
        printf("height: %d\n", get_height(root));
        printf("------------------\n");
        #endif
    }

    free_tree(root);
}

int main(int argc, char *argv[])
{
    test(argc, argv);
    return 0;
}
