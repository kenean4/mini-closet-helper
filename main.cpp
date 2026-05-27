#include <iostream>
#include "closet.h" 
using namespace std;
using namespace closet;



int main() {
  Closet myCloset;
  myCloset.loadCloset();
 
  int choice = 0;

   while(choice!= 5){

      cout << '\n' << "HELLO DRIPLESS DORKS!" << '\n' << "How may I help thy today?" <<'\n';
      cout <<"1.Add new clothing item"<< '\n' ;
      cout <<"2.View all items" <<'\n' ;
      cout <<"3.Search by color or occasion" << '\n';
      cout <<"4.Suggest random outfit" << '\n' ;
      cout <<"5.Exit" << '\n' << '\n';
      cout << "Enter Choice: ";
      cin >> choice;

      switch (choice){
         case 1:
          myCloset.addItem();
            break;
         
         case 2:
          myCloset.viewItem();
            break;

         case 3: 
          myCloset.searchItem();
            break;

         case 4:
          myCloset.suggestOutfit(); 
            break; 

         default: cout << "Please enter number 1 to 5";
      }
   
    
   }   

myCloset.saveCloset();
   
   return 0 ;
}


