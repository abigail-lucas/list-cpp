#include <exception>
#include "list.h"

class IndexOutOfRange : public std::exception {
    virtual const char* what() const throw() {
        return "IndexError: Index Out Of Range";
    }
} ioor;

class PopFromEmptyList : public std::exception {
    virtual const char* what() const throw() {
        return "IndexError: pop from empty list";
    }
} pfel;

List::List() {
    /* list constructor 
     * No input: initialize our array at length 2
     */
    capacity = 2;
    arr = new int[2]; // Add an array of 2 if no length is given
    ln = 0;
}

List::List(int l) {
    /* list constructor 
     * Input: we can size the array accordingly
     */
    capacity = l;
    arr = new int[l]; // Add an array of the given size
    ln = 0;
}

List::~List() {
    if (arr) {
        delete [] arr;
    }
}

int List::get(int i) {
    if (i >= ln) {
        throw ioor;
    }
    return arr[i];
}

int List::length() {
    return ln;
}

void List::resize(int c) {
    int* temp;
     temp = new int[c];
    for(int i=0; i < ln; i++) {
        temp[i] = arr[i];
    }
    capacity = c;
    delete [] arr;
    arr = temp;
}

void List::append(int n) {
    
    if(ln >= capacity) {
        resize(capacity*2);
    }
    arr[ln] = n;
    ln++;
}

void List::extend(int n[], int l) {
    if((ln + l) >= capacity) {
        int new_size;
        if((ln + l) >= capacity*2) {
            new_size = (ln + l) * 2;
        }
        else {
            new_size = capacity * 2;
        }
        resize(new_size);
    }

    for(int i=0; i < l; i++) {
        arr[ln+i] = n[i];
    }
    ln += l;
}

void List::pop() {
    // This method just shrinks the list length by one
    if (ln <= 0) {
        throw pfel;
    }

    ln -= 1;
}

void List::pop(int i) {
    // This method removes an element at a specific place in the list
    if(ln <= 0) {
        throw pfel;
    }
    if(i >= ln) {
        throw ioor;
    }

    for(int r=(i+1); r < ln; r++) {
        int temp = arr[r];
        arr[r-1] = temp;
    }
    ln -= 1;
}

void List::pop(int s, int e) {
    // This method removes a range of elements
    if(ln <= 0){
        throw pfel;
    }
    if(s <= 0) {
        throw ioor;
    }
    if(e >= ln) {
        throw ioor;
    }

    int diff = e - s + 1;
    for(int r=(e+1); r < ln; r++) {
        int temp = arr[r];
        arr[r-diff] = temp;
    }
    ln -= diff;
}
