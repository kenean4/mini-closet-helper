#include <iostream>
#include <cstdlib>
#include "closet.h"
 
using namespace std;

namespace closet {

void clothingItem:: printItem(int i){
   cout << "#" << i + 1 << " ";
    cout << color << " " ;
    cout << type << " - ";
    cout << "ideal for " << occasion << '\n';
}




void Closet :: addItem() {
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

void Closet:: viewItem(){

 for (int i=0; i< itemCount; i++) {   
     item[i].printItem(i);
    }
}


void Closet:: searchItem() {
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
                item[i].printItem(i);

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
               
               item[i].printItem(i);

                foundOccasion = true;
            }
         }
          if( foundOccasion != true){
             cout<< "You don't have that hon... " << '\n'; }

   }

}


void Closet:: suggestOutfit(){

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
            (item[topIndex]. type != "hoodie" &&
             item[topIndex]. type!= "jacket" &&
             item[topIndex]. type!= "shirt" &&
             item[topIndex]. type!= "t-shirt" &&
             item[topIndex]. type!= "crewneck");
     
          item[topIndex]. printItem(topIndex);
    
          do { bottomIndex = rand() % itemCount;
         }
          while
            (item[bottomIndex]. type != "jeans" &&
             item[bottomIndex]. type != "sweatpants" &&
             item[bottomIndex]. type != "skirt" &&
             item[bottomIndex]. type != "shorts" &&
             item[bottomIndex]. type != "cargo" );

          item[bottomIndex]. printItem(bottomIndex);
   
   }
}
}

