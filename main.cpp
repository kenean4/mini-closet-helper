#include <iostream>
#include "closet.h" 
// including the header file pulls in everything that we declared in it and so we don't need to write them again. 
using namespace std;
using namespace closet;



int main() {
   Closet myCloset;
   /* Here, we are creating an object called myCloset based on the structure of the class closet because the class
   itself is just a blueprint and doesn't actually hold any data or do anything its not even a storage its just a
   design for one the object is the actual storage*/ 

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
           // types of the function(like void,int ...) isn't needed only the argument is written here.
          /* the myCloset.addItem does the same thing as Closet::addItem but the closet::addItem was defining which class 
          the fuction belongs to, where the logic lives and what it can access and this one is the actual implementation telling the compiler
          to go to the object myCloset and call the function addItem to do its job.*/
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



   return 0 ;
}


