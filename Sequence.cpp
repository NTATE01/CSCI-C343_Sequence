#pragma once
#include "Sequence.hpp"
#include <iostream>
using namespace std;
int main()
{
    Sequence<int> seq;
    int x = 1;
    int y = 2;
    int z = 3; 

    seq.add(x, 0);
    seq.outputSequence();
    cout<<"\n";
    cout <<"seq after add x\n";
    seq.add(y,1);
    cout <<"seq after add y\n";
    seq.outputSequence();
    return 0;
} //main
/*
template <class T>
class Sequence
{
private: // Internal Representation

    class NodeRecord {
    public:
        T value;
        NodeRecord* next;
    };
    NodeRecord* head;
    int size;

public:
    Sequence();
    ~Sequence();
    void clear(void);

    //implement the following four functions
    void add(T& x, int pos);
    //! updates self
    //! restores pos
    //! clears x
    //! requires: 0 ? pos ? |self|
    //! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)

    void remove(T& x, int pos);
    //! updates self
    //! restores pos //! replaces x
    //!requires: 0 ? pos < |self|
    //!ensures: <x> = #self[pos, pos+1) and
    //!        self = #self[0, pos) * #self[pos+1, |#self|)

    T& entry(int pos);
    //! restores self, pos
    //! requires: 0 ? pos < |self|
    //! ensures: <entry> = self[pos, pos+1)

    int length(void);
    //! restores self
    //! ensures: length = |self|

    void outputSequence(void);
    //! restores self
    //! ensures: self = #self
    
    void moveItemsFromS1ToS2(Sequence& s1, Sequence& s2);
    //! updates s1
    //! replaces s2
    //! ensures: all items in #s1 located in even numbered positions
    //!          have been removed and put into s2 in same order.   
    //!          The items remaining in s1 & s2 are in the same order
    //!          as they were in #s1 & #s2. Consider index 0 to be even.

    void split(int pos, Sequence& receivingS);
     //! updates self
     //! restores pos
     //! replaces receivingS
     //! requires: 0 <= pos <= |self|
     //! ensures: self = #self[0, pos) and
     //!          receivingS = #self[pos, |self|)

private: // Internal operations
    void reclaimAllNodes(NodeRecord*& p);
};

template <class T>
Sequence<T>::Sequence()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
    reclaimAllNodes(head);
}    // ~Sequence


template <class T>
void Sequence<T>::clear(void)
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list
//           beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.
template <class T>
void Sequence<T> ::add(T& x, int pos) {
    if (pos > size)
        cout << "\nInvalid position entered \n";
    else {
        if (pos == 0) {
            NodeRecord* temp = new NodeRecord;
            temp->next = head;
            head = temp;
            head->value = x;
            size++;
        }//If Statement
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }//For Statement
            NodeRecord* var = new NodeRecord;
            var->next = current->next;
            current->next = var;
            size++;
            var->value = x;
        }// else
    }// else
}// add


template <class T>
void Sequence<T>::remove(T& x, int pos) {
    if (pos >= size) {
        cout << "Enter valid position, position " << pos << " is invalid";
    }// if
    else {
        if (pos == 0) {
            NodeRecord* temp = head;
            head = head->next;
        }// if
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }// for 
            NodeRecord* temp = current->next;
            current->next = temp->next;
            x = temp->value;
            delete temp;
            size--;
        }// else
    }//else
}// remove


template <class T>
T& Sequence<T>::entry(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Please enter valid position " << pos << " is invalid in this sequence ";
        return head->value;
    }// if
    else {
        NodeRecord* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }// for
        return current->value;
    }// else
}// entry


template <class T>
int Sequence<T>::length(void) {
    return size;
}// length 


template <class T>
void Sequence <T> ::outputSequence(void) {
    if (size == 0) {
        cout << "Sequence is Empty\n";
        return;
    }//if 
    else {
    	NodeRecord* current = head;
        cout << "[";
    	while (current != NULL) {
            if(current->next == NULL){
                cout << current->value;
                current = current->next;
            }
            else{
                cout << current->value;
                cout << "-";
                current = current->next;
            }
        }// while
    }// else
    cout << "]";
}// outputSentence

template <class T>
void Sequence<T>:: moveItemsFromS1ToS2(Sequence& s1, Sequence& s2){
    for(int i =0; i < s1.length(); i++){
        if(i == 0 || i % 2 == 0){
            int x = s1.entry(i);
            s1.remove(i,x);
            s2.add(i, x);
        }// if 
    }// for
}// moveItemsFromS1ToS2
//----------- main function for Sequence class---------------------------
*/
