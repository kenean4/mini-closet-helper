#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "closet.h"

 
using namespace std;

namespace closet {

void Closet :: addItem() {
      
      string tempoType;
    
      cout << "Enter type (hoodie, crewneck, jacket, t-shirt, shirt, skirt, sweatpants, jeans, cargo...):";
      cin >> tempoType;
      cout << "You have entered the type  " << tempoType << '\n';

      
      if (tempoType == "hoodie"|| tempoType == "crewneck" || 
         tempoType == "t-shirt"|| tempoType == "jacket"|| tempoType== "shirt")
        {item[itemCount] = new Top();} 

      else if (tempoType == "skirt"|| tempoType == "jeans"|| tempoType == "cargo"
               || tempoType == "shorts"|| tempoType == "sweatpants") 
            {item[itemCount] = new Bottom();} 

      else {
        cout << "Ok Mr. fancy, Idk what that is just pick a type from the provided options and make sure you're using small letters.\n";
      return;}
       
      item[itemCount]->type = tempoType;

      cout <<  "Enter color: ";
      cin >> item[itemCount]->color;
      cout << "You have entered the color " << item[itemCount]->color << '\n';

      cout << "Enter ideal occassion: ";
      cin >> item[itemCount]->occasion;
      cout << "You have entered the occasion " << item[itemCount]-> occasion << '\n';

      cout << '\n' << "Congratulations! you now have " << itemCount + 1 << " clothes...pathetic" << '\n';

     if (itemCount >= max_num ){
        cout << " Unlike your misery, my closet has a limit and you've reched it. ";
     }
       
        itemCount++;
        saveCloset();
}

void Closet:: viewItem(){

 for (int i=0; i< itemCount; i++) {   
     item[i]->printItem(i);
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
   
    switch(searchItem){
     
       case 1:
          cout << "Enter color: ";
          cin >> searchColor;
          
          for (int i=0; i< itemCount; i++){
              if (item[i]->color == searchColor){
                item[i]->printItem(i);
                
                foundColor = true;} }
         
          if (foundColor != true){
             cout<< "You don't have that hon... " << '\n'; }
       break;

       case 2:
          cout << "Enter occasion: ";
          cin >> searchOccasion;
          
          for (int i=0; i< itemCount; i++){
             if (item[i]->occasion == searchOccasion){
               item[i]->printItem(i);

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
bool hasTop = false;
bool hasBottom = false;

    switch(itemCount){
       case 0:
           cout <<" Respectfully, WHAT EXACTLY DO YOU WANT ME TO DO WITH NO CLOTHS HUH?!?" <<'\n';
       break;
       case 1:
          cout <<"No brokie you need to have atleast 2 clothes to generate an outfit!" <<'\n';
       break;
   
       default: 

          for(int i=0; i < itemCount; i++ ){
             if(item[i] -> isTop()) { hasTop = true;} 
             if (item[i] -> isBottom()) {hasBottom = true;}}
          
          if (hasTop == false || hasBottom == false){
              cout << "Are you comfortable with being only partially clothed? Yea didn't think so";
              return;}

          do { topIndex = rand() % itemCount;}
          while
            (!item[topIndex]-> isTop());
          item[topIndex]-> printItem(topIndex);
          
          do { bottomIndex = rand() % itemCount;}
          while
            (!item[bottomIndex]-> isBottom());
          item[bottomIndex]-> printItem(bottomIndex);
   }
}
void Closet:: saveCloset() {
   ofstream closetFile ("closet.txt");
   for (int i=0; i< itemCount; i++){
      closetFile <<item[i]->type <<","<<item[i]->color<<","<< item[i]->occasion<<'\n';
   } 
   closetFile.close();

}
void Closet:: loadCloset(){
   ifstream closetFile("closet.txt");
   string nextLine;
   string typ, col, occ;

   while(getline(closetFile,nextLine)){
      stringstream parser(nextLine);
      getline(parser, typ, ',');
      getline(parser, col, ',');
      getline(parser, occ);

       if (typ == "hoodie"|| typ == "crewneck" || 
         typ == "t-shirt"|| typ == "jacket"|| typ== "shirt")
        {item[itemCount] = new Top();} 

      else if (typ == "skirt"|| typ == "jeans"|| typ == "cargo"
               || typ == "shorts"|| typ == "sweatpants") 
            {item[itemCount] = new Bottom();} 

      item[itemCount]->type= typ;
      item[itemCount]->color= col;
      item[itemCount]->occasion= occ;

      itemCount++;
   }
   closetFile.close();
}

}

