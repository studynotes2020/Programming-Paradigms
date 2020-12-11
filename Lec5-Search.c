#include <stdio.h>
#include <string.h>

void *bsearch(void *key, void *base, int n, int elemSize, int (*cmp)(void*, void*)); // TODO: Implement binary search

int IntCmp(void *elem1, void *elem2)
{
    int *ip1 = elem1;
    int *ip2 = elem2;

    return *ip1 - *ip2;
}

int StrCmp(void *vp1, void *vp2)
{
    char *s1 = *(char**)vp1; // dereferencing in front so that s1 point to address vp1 pointint to
    char *s2 = *(char**)vp2;

    return strcmp(s1, s2);
}

void *lsearch(void *key, void *base,
            int n, int elemSize, 
            int (*cmpfn)(void *, void *))
{
    for (int i = 0; i < n; i++) {
        // cast char* so that void *base can do pointer arithmetic
        void *elemAddr = (char*)base + i * elemSize;
        if (cmpfn(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}

int main() {
    int arr[] = {4, 2, 3, 7, 11, 6};
    int size = 6;
    int number = 6;

    int *found = lsearch(&number, arr, 
                        6, sizeof(int),
                        IntCmp);
    if (found == NULL)
        printf("Not Found\n");
    else
        printf("Found\n");

    char *notes[] = {"Ab", "F#", "B", "Gb", "D"};
    char *favoriteNote = "Eb";
    // size of char* is same size as char**, char**** ..., all char pointers are of same bytes
    char **found2 = lsearch(&favoriteNote, notes,
                            5, sizeof(char*),
                            StrCmp);

    if (found2 == NULL)
        printf("Not Found\n");
    else
        printf("Found\n");

    return 0;
}