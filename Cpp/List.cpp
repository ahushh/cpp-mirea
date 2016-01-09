#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// Список 
template <class T> 
class List;

template <class T>
class ListNode {
    friend class List<T>;
public:
    ListNode(T);
    T get();
private:
    T data;
    ListNode* nextPtr;
};

template <class T>
ListNode<T>::ListNode(T dataIn) {
    data = dataIn;
    nextPtr = NULL;
}

template <class T>
T ListNode<T>::get(){
    return data;
}

template <class T>
class List {
public:
    List();
    ~List();
    void insertEnd(T);
    void deleteEnd();
    void print();
    ListNode<T>* at(int);
private:
    ListNode<T> *startPtr;
    ListNode<T> *endPtr;
    bool isEmpty();
};


template <class T>
List<T>::List() {
    startPtr = NULL;
    endPtr = NULL;
}

template <class T>
List<T>::~List() {
    if (!isEmpty()) {    
        return; 
    }
    ListNode<T> *currentPtr = startPtr;
    ListNode<T> *tempPtr;
    while (currentPtr != NULL) {  
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        delete tempPtr;
    }
}

template <class T>
bool List<T>::isEmpty() {
    return startPtr == NULL && endPtr == NULL;
}

template <class T>
void List<T>::deleteEnd(){
    ListNode<T> * currentPtr = startPtr;
    while (currentPtr != NULL) {
        if (currentPtr->nextPtr == endPtr) {
            endPtr = currentPtr;
            endPtr->nextPtr = NULL;
            return;
        }
        currentPtr = currentPtr->nextPtr;
    }
}

template <class T>
void List<T>::insertEnd(T dataIn){
    if (isEmpty()) {
        ListNode<T> * newPtr = new ListNode<T>(dataIn);
        startPtr = newPtr;
        endPtr = newPtr;
    } else {
        ListNode<T> * newPtr = new ListNode<T>(dataIn);
        endPtr->nextPtr = newPtr;
        endPtr = newPtr;
    }
}

template <class T>
void List<T>::print() {
    if (isEmpty()) {
        cout << "The list is empty" << endl;
        return;
    }
    ListNode<T> * currentPtr = startPtr;
    while (currentPtr != NULL) {
        cout << currentPtr->data;
        currentPtr = currentPtr->nextPtr;
    }
}

template <class T>
ListNode<T>* List<T>::at(int n) {
    ListNode<T>* nodePtr;
    bool found = false;

    nodePtr = startPtr;
    int i = 0;
    while ((!found) && (nodePtr != NULL)) {
        if (i == n)
            found = true;
        else
            nodePtr = nodePtr->nextPtr;
        i++;
    }
    return nodePtr;
}

// Ряд
class Series {
private:
    double *arr;
    int N;
public:
    Series() {}
    Series(double *a, int n): arr(a), N(n) { }

    friend ostream& operator<<(ostream& os, Series& s) {
        int N = s.getSize();
        for (int i = 0; i < N; i++) os << s.get(i) << " ";
        os << endl;
        return os;
    }

    double getSize() {
        return N;
    }

    double get(int i) {
        return arr[i];
    }

    void sort(int first, int last) {
        int l = first;
        int r = last;
        int p = first;

        do { 
            while (arr[l] < arr[p])
                l++;
            while (arr[r] > arr[p])
                r--;
         
            if (l <= r) { 
                double temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        } while (l <= r);
         
        if (l < last)
            sort(l, last);
        if (r > first)
            sort(first, r);
    }
};

int main() {
    srand (time(NULL));

    int N1 = 5;
    double* a1 = new double[N1];
    for (int i = 0; i < N1; i++) a1[i] = (double)( rand() % 100);
    Series s1 = Series(a1, N1);
    cout << "Series s1: " << endl;
    cout << s1;
    s1.sort(0, N1-1);
    cout << "After sorting: " << endl;
    cout << s1;

    int N2 = 6;
    double* a2 = new double[N2];
    for (int i = 0; i < N2; i++) a2[i] = (double)( rand() % 100);
    Series s2 = Series(a2, N2);
    cout << "Series s2: " << endl;
    cout << s2;
    s2.sort(0, N2-1);
    cout << "After sorting: " << endl;
    cout << s2;

    cout << "List containing series s1 and s2: " << endl;
    List<Series> l = List<Series>();
    l.insertEnd( s1 );
    l.insertEnd( s2 );
    l.print();
    cout << "Get element of list by index 1: " << endl;    
    Series s3 = l.at(1)->get();
    cout << s3;
    return 0;
}
