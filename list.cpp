#include "list.h"

list::list() {
    /* list constructor 
     * No input: initialize our array at length 2
     */
    capacity = 2;
    arr = new int[2]; // Add an array of 2 if no length is given
    ln = 0;
}

list::list(int l) {
    /* list constructor 
     * Input: we can size the array accordingly
     */
    capacity = l;
    arr = new int[l]; // Add an array of the given size
    ln = 0;
}

list::~list() {
    if (arr) delete [] arr;
}

int list::get(int i) {
    return arr[i];
}

int list::length() {
    return ln;
}

void list::append(int n) {
    int* temp;
    
    if(ln >= capacity) {
        temp = new int[capacity*2]; // Double our array size
        for(int i=0; i < ln; i++) {
            temp[i] = arr[i];
        }
        capacity *= 2;
        delete [] arr;
        arr = temp;
    }
    arr[ln] = n;
    ln++;
}
