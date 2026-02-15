#ifndef HEADER_H
#define HEADER_H

//struct definition
#include <string>
using namespace std;

struct Person{
  string name;
  string surname;
  long phone;
  Person* next;
};


//function  declarations
void clearAll(Person* &head);
void addLast(Person* &head);
void print(Person* head);
void search(Person* head);
void remove(Person* &head);
void expt(int argc, char* argv[], Person* head);
#endif // HEADER




