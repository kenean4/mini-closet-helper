#include <iostream>
#include <string>
#include "closet.h" 
using namespace std;


int main() {

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
          closet:: addItem(); // types of the function(like void,int ...) isn't needed only the argument is written here.
            break;
         
         case 2:
          closet:: viewItem();
            break;

         case 3: 
          closet:: searchItem();
            break;

         case 4:
          closet:: suggestOutfit(); 
            break; 

         default: cout << "Please enter number 1 to 5";
      }
   
    
   }   

   delete [] closet::type;
   delete [] closet::color;
   delete [] closet::occasion;


   return 0 ;
}


