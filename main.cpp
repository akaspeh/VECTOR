#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include "DynamicArr.h"
#include "LinkedList.h"
using namespace std;


struct Mem{
char sample[13];
char text[10];
short amountlikes;
    friend std::ostream& operator<< (std::ostream &out, const Mem &Mem);
};


Mem random_mem(){
Mem a;
string arrSAMPLE[] = {"square","Rectangular","Round","Triangular","Ellipse","Rhombus"};
string arrTEXT[] = {"wp","gg","na dopku","otchislen","Matan","Linal"};
strcpy(a.sample, (arrSAMPLE[rand()%6]).c_str());
strcpy(a.text, (arrTEXT[rand()%6]).c_str());
    a.amountlikes = rand()%100;
    return a;
}


std::ostream& operator<< (std::ostream &out, const Mem &Mem)
{
    out << "Mem(" << Mem.sample << " " << Mem.text << " " <<Mem.amountlikes <<")";
    return out;
}


using namespace std;


void test1(DynamicArr <Mem> *Array){
    clock_t startTime = clock();
    for(int i=0; i < 50000;i++){
       Array->push_back(random_mem());
    }
    clock_t endTime = clock();
    double seconds1 = (double (endTime - startTime)) / CLOCKS_PER_SEC;
    cout << seconds1 << endl;

    clock_t startTime2 = clock();
    for(int i=0; i < 10000;i++){
        Array->push_front(random_mem());
    }
    clock_t endTime2 = clock();
    double seconds2 = (double (endTime2 - startTime2)) / CLOCKS_PER_SEC;
    cout << seconds2 << endl;

    clock_t startTime3 = clock();
    for(int i=0; i < 20000;i++){
        Array->get(rand()%50000);
    }
    clock_t endTime3 = clock();
    double seconds3 = (double (endTime3 - startTime3)) / CLOCKS_PER_SEC;
    cout << seconds3 << endl;

    clock_t startTime4 = clock();
    for(int i=0; i < 5000;i++){
        Array->pop_back();
    }
    clock_t endTime4 = clock();
    double seconds4 = (double (endTime4 - startTime4)) / CLOCKS_PER_SEC;
    cout << seconds4 << endl;

    clock_t startTime5 = clock();
    for(int i=0; i < 5000;i++){
        Array->pop_front();
    }
    clock_t endTime5 = clock();
    double seconds5 = (double (endTime5 - startTime5)) / CLOCKS_PER_SEC;
    cout << seconds5 << endl;
}

void test2(LinkedList <Mem> *List){
    clock_t startTime = clock();
    for(int i=0; i < 50000;i++){
        List->push_back(random_mem());
    }
    clock_t endTime = clock();
    double seconds1 = (double (endTime - startTime)) / CLOCKS_PER_SEC;
    cout << seconds1 << endl;

    clock_t startTime2 = clock();
    for(int i=0; i < 10000;i++){
        List->push_front(random_mem());
    }
    clock_t endTime2 = clock();
    double seconds2 = (double (endTime2 - startTime2)) / CLOCKS_PER_SEC;
    cout << seconds2 << endl;

    clock_t startTime3 = clock();
    for(int i=0; i < 20000;i++){
        List->get(rand()%50000);
    }
    clock_t endTime3 = clock();
    double seconds3 = (double (endTime3 - startTime3)) / CLOCKS_PER_SEC;
    cout << seconds3 << endl;

    clock_t startTime4 = clock();
    for(int i=0; i < 5000;i++){
        List->pop_back();
    }
    clock_t endTime4 = clock();
    double seconds4 = (double (endTime4 - startTime4)) / CLOCKS_PER_SEC;
    cout << seconds4 << endl;

    clock_t startTime5 = clock();
    for(int i=0; i < 5000;i++){
        List->pop_front();
    }
    clock_t endTime5 = clock();
    double seconds5 = (double (endTime5 - startTime5)) / CLOCKS_PER_SEC;
    cout << seconds5 << endl;
}


int main() {

    srand (time(NULL));
    int b;
    cin >> b;
    if(b == 1) {
        DynamicArr<Mem> Array;
        while (1 == 1) {
            string a;
            cin >> a;
            if (a == "pop_back()") {
                Mem Mem1 = Array.pop_back();
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "push_back()") {
                Mem Mem1 = random_mem();
                Array.push_back(Mem1);
            }
            if (a == "get()") {
                cout << "enter num";
                int N;
                cin >> N;
                Mem Mem1 = Array.get(N);
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "size()") {
                cout << Array.size();
            }
            if (a == "push_front()") {
                Mem Mem1 = random_mem();
                Array.push_front(Mem1);
            }
            if (a == "pop_front()") {
                Mem Mem1 = Array.pop_front();
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "print()") {
                Array.print();
            }
            if (a == "clear()") {
                Array.clear();
            }
            if (a == "test()") {
                test1(&Array);
            }
            if (a == "exit()") {
                break;
            }
        }
    }
    else{
        LinkedList<Mem> List;
        while (1 == 1) {
            string a;
            cin >> a;
            if (a == "pop_back()") {
                Mem Mem1 = List.pop_back();
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "push_back()") {
                Mem Mem1 = random_mem();
                List.push_back(Mem1);
            }
            if (a == "get()") {
                cout << "enter num";
                int N;
                cin >> N;
                Mem Mem1 = List.get(N);
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "size()") {
               cout << List.size();
            }
            if (a == "push_front()") {
                Mem Mem1 = random_mem();
                List.push_front(Mem1);
            }
            if (a == "pop_front()") {
                Mem Mem1 = List.pop_front();
                Mem Mem2 = Mem{};
                if(Mem1.sample != Mem2.sample and Mem1.text != Mem2.text  and Mem1.amountlikes != Mem2.amountlikes){
                    cout << Mem1 << '\n';
                }
            }
            if (a == "print()") {
                List.print();
            }
            if (a == "clear()") {
                List.clear();
            }
            if (a == "test()") {
                test2(&List);
            }
            if (a == "exit()") {
                break;
            }
        }
    }
    return 0;
}
