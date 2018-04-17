Function prototypes:
====================

Initialize:
-----------

Declare NODE type variable and init it with NULL value.


```c
NODE *root = NULL;
```

Insert:
-------

To insert data using key, pass both address of data and key along woth the
address of root variable to insert_avl.

```c
void insert_avl(NODE **root_ptr, void *data, void *key);

/* example */

...
int *i = calloc(1, sizeof(int));
*i = 10;
char *val = strdup("hello");
insert_avl(&root, val, i);
...
```

Deletion:
---------

Pass address of key and root variable to delete_avl. It returns the address to
the data.

```c
void *delete_avl(NODE **root_ptr, void *key)

/* example */

void *data = delete_avl(&root, key);
```

Lookup:
-------

Return value is null if key not present. Else returns the data.

```c
void *lookup_avl(NODE *root, void *key)

/* example */

int *i = calloc(1, sizeof(int));
*i = 10;
void *data = lookup_avl(root, key);
```
