#include <string.h>

void rotate(void *front, void *middle, void *end)
{
    int frontSize = (char*)middle - (char*)front;
    int backSize = (char*)end - (char*)middle;
    char buffer[frontSize];
    // memcpy loops over the data (in order), copying from one 
    // location to the other. This can result in the source being 
    // overwritten while it's being read.
    memcpy(buffer, front, frontSize);  // memcpy more efficiency
    memmove(front, middle, backSize);  // memmove when there is chance of overlapping
    memcpy((char*)end - frontSize, buffer, frontSize);
}

void qsort(void *base, int size, int elemSize, int (*cmpfn)(void *, void *))
{
    
}