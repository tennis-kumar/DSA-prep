#include <stdio.h>
#include <stdlib.h>

struct arrayADT
{
    int total_size;
    int used_size;
    int* ptr;
};

void createArray(struct arrayADT* a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize*sizeof(int));
    
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize * sizeof(int));
}

void show(struct arrayADT * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}

void setVal(struct arrayADT *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
       printf("Enter element %d: ", i);
       scanf("%d",&n);
       (a->ptr)[i] = n;
    }
    
}

int main(){
    struct arrayADT marks;
    createArray(&marks, 10, 2);
    printf("we are running setval now\n");
    setVal(&marks);
    printf("we are running show now\n");
    show(&marks);
    return 0;
}