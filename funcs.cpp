#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;


void clearAll(Person* &head){
  if(head == nullptr){
    cout << "Nothing to clear, list already empty!\n";
    return;
  }
  while(head->next != nullptr){
    Person* temp = head;
    head = head->next;
    delete temp;
  }
  delete head;
  head = nullptr;
}


void addLast(Person* &head){
  cout << "--- ADDING NEW CONTACT ---\n";
  if(head == nullptr){
    head = new Person;
    cout << "Name: ";
    cin >> head->name;
    cout << "Surname: ";
    cin >> head->surname;
    cout << "Phone number: ";
    cin >> head->phone;
    head->next = nullptr;
    return;
  }
  Person* current = head;
  Person* newNode = new Person;
  cout << "Name: ";
  cin >> newNode->name;
  cout << "Surname: ";
  cin >> newNode->surname;
  cout << "Phone number: ";
  cin >> newNode->phone;
  while(current->next != nullptr){
    current = current->next;
  }
  current->next = newNode;
  newNode->next = nullptr;
}



void print(Person* head){
  if(head == nullptr){
    cout << "Nothing to print here, it looks like you have no friends!\n";
    return;
  }
  Person* current = head;
  while(current != nullptr){
    cout << "Name: " << current->name << endl;
    cout << "Surname: " << current->surname << endl;
    cout << "Phone number: " << current->phone << endl;
    current = current->next;
    cout <<  endl;
  }
}


void search(Person* head){
  if(head == nullptr){
    cout <<  "List is empty, are you perhaps looking for nothing?\n";
    return;
  }
  string targetName;
  cout << "Enter name: ";
  cin >> targetName;
  Person* current = head;
  int counter = 0;
  while(current != nullptr){
    if(current->name == targetName){
      cout << "Name: " << current->name << endl;
      cout << "Surname: " << current->surname << endl;
      cout << "Phone number: " << current->phone << endl;
      cout << endl;
      counter++;
    }
    current = current->next;
  }
  if(counter == 0){
    cout << "Contact not found!\n";
    return;
  }
  cout << "Found " << counter << " with name " << targetName << endl;
}


void remove(Person* &head){
  if(head == nullptr){
    cout << "List is empty, try to make some friends before removing them!\n";
    return;
  }
  Person* current = head->next;
  Person* prev = head;
  string targetName;
  string targetSur;
  cout << "Name: ";
  cin >> targetName;
  cout << "Surname: ";
  cin >> targetSur;
  
  if(targetName == head->name && targetSur == head->surname){   //targert to delete is head
    Person* temp = head;
    head = head->next;
    delete temp;
  }


  while(current != nullptr){
    if(current->name == targetName && current->surname == targetSur){ //target is anything else
      prev->next = current->next;
      delete current;
    }
    prev = current;
    current = current->next;
  }

  cout << "Delete " << targetName << " " << targetSur << " from your list with success!\n";
}


void expt(int argc, char* argv[], Person* head){
  fstream out;
  out.open("List.txt", ios::out);
  Person* current = head;
  while(current != nullptr){
    out << endl;
    out << "Name: " << current->name << endl;
    out << "Surname: " << current->surname << endl;
    out << "Phone number: " << current->phone << endl;
    current = current->next;
  }
  cout << "List exported with success!\n";
  out.close();
}

void imp(int argc, char* argv[], Person* head){
  if argc < 2{
    cout << "Error, no input file provided at start\nRun contacts input.txt to use this option\n";
    return;
  }
  
}




