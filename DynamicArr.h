//
// Created by PC on 22.02.2022.
//
#include <iostream>
#include <cstdlib>

#ifndef VECTOR_DYNAMICARR_H
#define VECTOR_DYNAMICARR_H

template <class T>
class DynamicArr {
private:
    int sizearr;
    int cur;
    void resize_arr(T *&arr,char a){
        if(a == '>') {
            T *new_arr = new T[sizearr*2];
            for (int i = 0; i < sizearr; i++) {
                new_arr[i] = arr[i];
            }
            sizearr *= 2;
            delete[] arr;
            arr = new_arr;
        }
        else if(a == '<'){
            T *new_arr = new T[sizearr/2];
            for (int i = 0; i < sizearr; i++) {
                new_arr[i] = arr[i];
            }
            sizearr /= 2;
            delete[] arr;
            arr = new_arr;
        }
    }
public:
    //Constructor
    DynamicArr(){
        sizearr=1;
        cur=-1;
    }
    //Destructor
    ~DynamicArr(){
        delete [] Array;
    }

    T *Array = new T[sizearr];

    void push_back(T element){
        if(cur == sizearr-1){
            resize_arr(Array,'>');
            cur++;
        }
        else{
            cur++;
        }
        Array[cur] = element;
    }
    //-----------------//
    T pop_back(){
        if(cur < 0){
            return T{};
        }
        else if(cur == sizearr/2-1){
            resize_arr(Array,'<');
            cur--;
            return Array[cur+1];
        }
        else{
            cur--;
            return Array[cur+1];
        }
    }
    //-----------------//
    void print(){
        for(int i = 0; i<cur+1; i++){
            T a = Array[i];
            std::cout << a <<'\n';
        }
    }
    //-----------------//
    T get(int N){
        if(N<sizearr){
            return T{};
        }
        else{
            return Array[N];
        }
    }
    int size(){
        return cur+1;
    }
    void clear(){
        delete [] Array;
        sizearr = 1;
        cur=-1;
        Array = new T[sizearr];
    }
    void push_front(T element){

        if(cur == sizearr-1){
            std::cout << cur << '\n';
            std::cout << sizearr << '\n';
            resize_arr(Array,'>');
            for(int i = cur;i>=0;i--){
                Array[i+1]=Array[i];
            }
            std::cout << cur << '\n';
            std::cout << sizearr << '\n';
            cur++;
            Array[0] = element;
        }
        else{
            for(int i = cur;i>=0;i--){
                Array[i+1]=Array[i];
            }
            cur++;
            Array[0] = element;
        }
    }
    T pop_front(){
        if(cur < 0){
            return T{};
        }
        else if(cur == sizearr/2-1){
            resize_arr(Array,'<');
            for(int i =cur;i>=0;i--){
                Array[i]=Array[i+1];
            }
            cur--;
            return Array[0];
        }
        else{
            for(int i =0;i<cur;i++){
                Array[i]=Array[i+1];
            }
            cur--;
            return Array[0];
        }
    }
};

#endif //VECTOR_DYNAMICARR_H
