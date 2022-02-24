//
// Created by PC on 22.02.2022.
//

#ifndef VECTOR_LINKEDLIST_H
#define VECTOR_LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int cur = -1;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node *curr = head;
        for(int i = 0;i<cur;i++){
            curr = curr->next;
            delete head;
            head = curr;
        }
        delete head;
        head = nullptr;
    }
    void push_back(T element){
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;

        if(cur == -1){
            head = newNode;
            tail = newNode;
            cur++;
        }
        else{
            tail->next=newNode;
            tail = newNode;
            cur++;
        }
    }
    void push_front(T element){
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;

        if(cur == -1){
            head = newNode;
            tail = newNode;
            cur++;
        }
        else{
            cur++;
            newNode->next = head;
            head = newNode;
        }
    }
    T pop_front(){
        if(cur == -1){
            std::cout << "nothing to pop\n";
            return T{};
        }
        else{
            T a = head->data;
            Node *temp = head->next;
            delete head;
            head = temp;
            cur--;
            return a;
        }
    }
    T pop_back(){
        if(cur == -1){
            std::cout << "nothing to pop\n";
            return T{};
        }
        else{
            T a = tail->data;
            Node* second_last = head;
            while (second_last->next->next != nullptr)
                second_last = second_last->next;
            delete (second_last->next);
            second_last->next = nullptr;
            cur--;
            return a;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            std::cout << curr->data << '\n';
            curr = curr->next;
        }
    }
    int size(){
        return cur+1;
    }
    T get(int N){
        if(N>cur){
            return T{};
        }
        else{
            Node* curr = head;
            for(int i = 0; i != N;i++){
                curr = curr->next;
            }
            T a = curr->data;
            return a;
        }
    }
    void clear(){
        Node *curr = head;
        for(int i = 0;i<cur;i++){
            curr = curr->next;
            delete head;
            head = curr;
        }
        delete head;
        head = nullptr;
    }
};


#endif //VECTOR_LINKEDLIST_H
