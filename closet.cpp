#include <iostream>
#include <cstdlib>
#include "closet.h"
 
using namespace std;

namespace closet {
const int max_num = 20;
      int itemCount=0;

class clothingItem {
   public:
string type; //= new string[max_num];
string color; //= new string[max_num];
string occasion; //= new string[max_num];

void printItem(int i){
   cout << "#" << i + 1 << " ";
    cout << color[i] << " " ;
    cout << type[i] << " - ";
    cout << "ideal for " << occasion[i] << '\n';
};

class Closet {
   public:
   int itemCount = 0;
   clothingItem item[max_num];

void addItem() {
      //always include parameters when declaring a function
   

      cout << "Enter type (hoodie, crewneck, jacket, t-shirt, shirt, skirt, sweatpants, jeans, dress, cargo...):";
      cin >> item[itemCount].type;
      cout << "You have entered the type  " << item [itemCount].type << '\n';
            

      cout <<  "Enter color: ";
      cin >> item[itemCount].color;
      cout << "You have entered the color " << item[itemCount].color << '\n';

      cout << "Enter ideal occassion: ";
      cin >> item[itemCount].occasion;
      cout << "You have entered the occasion " << item[itemCount]. occasion << '\n';

      cout << '\n' << "Congratulations! you now have " << itemCount + 1 << " clothes...pathetic" << '\n';

     if (itemCount == max_num){
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
              if (item[i].color == searchColor){
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
             if (item[i].occasion == searchOccasion){
               
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
private: 

int itemCount=0;
         
};
}
}