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
void printVectorElements(Vector* v);
void popback(Vector* v);
void pushback(Vector* v, int element);
void popAtIndex(Vector* v, size_t index);
void pushAtIndex(Vector* v, int element, size_t index);

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

void printVectorElements(Vector* v){
    for(int x = 0; x < v->size; ++x){
        printf("Element %d: %d\n", x + 1, v->arr[x]);
    }
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

void popback(Vector* v){
    if(v->arr == NULL){
        printf("Vector uninitialized, Please reinitialize vector using init_vector()");
        return;
    }

    v->arr[v->size] = -1;
    v->size--;
}

void pushAtIndex(Vector* v, int element, size_t index){
    if(index >= v->size){
        printf("Not that many elements are present\n");
        return;
    }

    //double vector size if cannot push element
    if(v->size == v->capacity){
        v->capacity = (v->capacity) * 2;
        v->arr = realloc(v->arr, v->capacity * sizeof(int));
    }

    //start at the valid empty slot
    size_t place_index = v->size;
    //go in reverse from the end of the vector to just before the specified index
    //shift the elements by place to the right
    for(place_index; place_index > index; --place_index){
        v->arr[place_index] = v->arr[place_index - 1];
    }

    //insert the element at the given index
    v->arr[index] = element;
    v->size++;
}

void popAtIndex(Vector* v, size_t index){
    if(index >= v->size){
        printf("Not that many elements are present");
        return;
    }

    for(index; index < v->size - 1; ++index){
        v->arr[index] = v->arr[index + 1];
    }

    printf("Current Index: %d\n", index);
    v->arr[v->size - 1] = -1;
    v->size--;
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

    int input = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &input);

    for(int x = 0; x < input; ++x){
        pushback(&v, x + 1);
    }

    // printVectorElements(&v);
    printf("Element at index 0: %d\n", v.arr[0]);
    printf("Element at index 1: %d\n", v.arr[1]);
    printVectorHealth(&v);
    pushAtIndex(&v, 69, 0);
    // printVectorElements(&v);
    printf("Element at index 0: %d\n", v.arr[0]);
    printf("Element at index 1: %d\n", v.arr[1]);
    printVectorHealth(&v);

    freeVector(&v);
    return 0;
}
