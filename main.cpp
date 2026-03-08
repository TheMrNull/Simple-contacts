#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;


int main(int argc, char* argv[]){
  int action;
  bool running = true;
  Person* head = nullptr;
  while(running){

  cout << "--------------\n";
  cout << "-- CONTACTS --\n";
  cout << "--------------\n";
  
  cout << "\nPlease choose an action:\n";
  cout << "1)Print\n2)Add\n3)Remove\n4)Search\n5)Export\n6)Import\n7)Quit\nAction: ";
  cin >> action;
  switch (action) {
    case 1:{
          cout << endl << endl << endl;
          print(head);
          break;
      }
    case 2:{
        addLast(head);
        break;
      }
    case 3:{ remove(head);
             break;
           }
    case 4:{
            search(head);
            break; 
           }
    case 5:{ expt(argc, argv, head);
             break;
           }
    case 6:{
            impt(argc, argv, head);
            break;
           }
    case 7:{
        clearAll(head);
        cout << "Saving changes and clearing memory!\nBye bye\n";
        running = false;
        break;
      }
  }
  }



  return 0;
}

