#include <iostream>
#include <cstdlib>
#include "closet.h"
 
using namespace std;

namespace closet {
int itemCount=0;
string type[20];
string color[20];
string occasion[20];

void printItem(int i){
   cout << "#" << i + 1 << " ";
    cout << color[i] << " " ;
    cout << type[i] << " - ";
    cout << "ideal for " << occasion[i] << '\n';

}


void addItem() {
      //always include parameters when declaring a function
   

      cout << "Enter type (hoodie, crewneck, jacket, t-shirt, shirt, skirt, sweatpants, jeans, dress, cargo...):";
      cin >> type[itemCount];
      cout << "You have entered the type  " << type[itemCount] << '\n';
            

      cout <<  "Enter color: ";
      cin >> color[itemCount];
      cout << "You have entered the color " << color[itemCount] << '\n';

      cout << "Enter ideal occassion: ";
      cin >> occasion[itemCount];
      cout << "You have entered the occasion " << occasion[itemCount] << '\n';

      cout << '\n' << "Congratulations! you now have " << itemCount + 1 << " clothes...pathetic" << '\n';

     if (itemCount > 20){
        cout << " Unlike your misery, my closet has a limit and you've reched it. ";
     }

        itemCount++;
}

void viewItem(){

 for (int i=0; i< itemCount; i++) {   
     printItem(i);
    }
}


void searchItem() {
   int searchItem ;
   string searchColor = "";
   string searchOccasion = "";
   bool foundColor = false;
   bool foundOccasion = false;
 
    cout << "1.Search by color" << '\n' << "2.Search by occasion " <<'\n';
    cin >> searchItem; 
   
    switch(searchItem)
     {
       case 1:
          cout << "Enter color: ";
          cin >> searchColor;
          for (int i=0; i< itemCount; i++){
              if (color[i] == searchColor){
                printItem(i);

                foundColor = true;
               }
            }
          if (foundColor != true){
             cout<< "You don't have that hon... " << '\n'; }
    
       break;

       case 2:
          cout << "Enter occasion: ";
          cin >> searchOccasion;
          for (int i=0; i< itemCount; i++){
             if (occasion[i] == searchOccasion){
               
               printItem(i);

                foundOccasion = true;
            }
         }
          if( foundOccasion != true){
             cout<< "You don't have that hon... " << '\n'; }

   }

}


void suggestOutfit(){

int topIndex;
int bottomIndex;

    switch(itemCount){
       case 0:
           cout <<" Respectfully, WHAT EXACTLY DO YOU WANT ME TO DO WITH NO CLOTHS HUH?!?" <<'\n';
       break;
       case 1:
          cout <<"No brokie you need to have atleast 2 clothes to generate an outfit!" <<'\n';
       break;
   
       default: 
          do { topIndex = rand() % itemCount;}
      
          while
             (type[topIndex] != "hoodie" &&
             type[topIndex] != "jacket" &&
             type[topIndex] != "shirt" &&
             type[topIndex] != "t-shirt" &&
             type[topIndex] != "crewneck");
     
          cout << "Top: ";
          cout << color[topIndex] << " " ;
          cout << type[topIndex] << " - ";
          cout << "ideal for " << occasion[topIndex] << '\n';

    
          do { bottomIndex = rand() % itemCount;
         }
          while
             (type[bottomIndex] != "jeans" &&
             type[bottomIndex] != "sweatpants" &&
             type[bottomIndex] != "skirt" &&
             type[bottomIndex] != "shorts" &&
             type[bottomIndex] != "cargo" );

    cout << "Bottom: ";
    cout << color[bottomIndex] << " " ;
    cout << type[bottomIndex] << " - ";
    cout << "ideal for " << occasion[bottomIndex] << '\n';
   
   }
}
}