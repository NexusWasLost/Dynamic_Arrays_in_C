#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array{
    int* arr; //should point to a contiguous memory block
    size_t size;
    size_t capacity;
}Vector;

Vector init_vector();
void freeVector(Vector* v);
void printVectorHealth(Vector* v);
void pushback(Vector* v, int element);

Vector init_vector(){
    Vector v;
    // initial size 0 = 0 elements
    v.size = 0;
    // initial capacity 4 elements
    v.capacity = 4;
    //allocated 16 bytes of heap memory
    v.arr = malloc(v.capacity * sizeof(int));
    return v;
}

void printVectorHealth(Vector* v){
    printf("Current Number of Elements Present: %d\n", v->size);
    printf("Current Vector Capacity: %d\n", v->capacity);
}

void pushback(Vector* v, int element){
    if(v->arr == NULL){
        printf("Vector uninitialized, Please reinitialize vector using init_vector()");
        return;
    }

    if(v->size == v->capacity){
        //set its capacity to be double from that of the old vector
        v->capacity = (v->capacity) * 2;
        //allocated memory for the new vector
        v->arr = realloc(v->arr, v->capacity * sizeof(int));
    }

    v->arr[v->size] = element;
    v->size++;

}

void freeVector(Vector* v){
    if(v->arr == NULL) return;
    free(v->arr);
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main(){

    Vector v = init_vector();

    // pushback(&v, 69);
    // pushback(&v, 79);
    // pushback(&v, 89);
    // pushback(&v, 99);
    // pushback(&v, 109);
    // pushback(&v, 119);
    // pushback(&v, 129);
    // pushback(&v, 139);
    // pushback(&v, 149);
    // pushback(&v, 159);
    // pushback(&v, 169);
    // pushback(&v, 179);
    // pushback(&v, 189);
    // pushback(&v, 199);

    int input = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &input);

    for(int x = 0; x <= input; ++x){
        pushback(&v, x + 1);
    }

    for(int x = 0; x < v.size; ++x){
        printf("Element %d: %d\n", x + 1, v.arr[x]);
    }

    printVectorHealth(&v);
    return 0;
}
