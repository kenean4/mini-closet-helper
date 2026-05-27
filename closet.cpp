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
      
      /*Closet::*a function xyz* means the function xyz which is found in the class Closet and we do that so that 
      the function can acess the variables declared in the class without listing them all in its parameter*/ 

    string tempoType;
    /*This is a temporary variable created to store the type entered by the console. It is needed because the 
      object where the type will be permanently stored can not be created yet as it is the type that determines on which
      class the object will be created, top or botom*/

      cout << "Enter type (hoodie, crewneck, jacket, t-shirt, shirt, skirt, sweatpants, jeans, cargo...):";
      cin >> tempoType;
      cout << "You have entered the type  " << tempoType << '\n';

      
      if (tempoType == "hoodie"|| tempoType == "crewneck" || 
          tempoType == "t-shirt"|| tempoType == "jacket"|| tempoType== "shirt")
      { item[itemCount] = new Top();} 
      /* new is what actually rents memory creates the object, Top is where it is created and item[itemCount]
      is where it's adress is stored since item is the array of pointers*/
      else if (tempoType == "skirt"|| tempoType == "jeans"|| tempoType == "cargo"
      || tempoType == "shorts"|| tempoType == "sweatpants") 
            {item[itemCount] = new Bottom();} // same thing here

      else {
    cout << "Ok Mr. fancy, Idk what that is just pick a type from the provided options and make sure you're using small letters.\n";
    return;
}
      item[itemCount]->type = tempoType;
      // This is where we place the type into its temporary home which is the object

      cout <<  "Enter color: ";
      cin >> item[itemCount]->color;
      /* Here we are saying follow the pointer item[itemCount], find the object it points to and 
         put the input recieved from the console into the property of the object called type*/
      cout << "You have entered the color " << item[itemCount]->color << '\n';
      /* - We say '->' because item[itemCount] is a pointer found in the array of pointers called item so the arrow means
          follow the pointer to the adress of the object it points to and check the property of the object called color
        - The actual object is found either in the class top or bottom*/

      cout << "Enter ideal occassion: ";
      cin >> item[itemCount]->occasion;
      cout << "You have entered the occasion " << item[itemCount]-> occasion << '\n';

      cout << '\n' << "Congratulations! you now have " << itemCount + 1 << " clothes...pathetic" << '\n';

     if (itemCount >= max_num ){
        cout << " Unlike your misery, my closet has a limit and you've reched it. ";
     }

        itemCount++;
}

void Closet:: viewItem(){

 for (int i=0; i< itemCount; i++) {   
     item[i]->printItem(i);
     // printItem is the function that holds the cout commands
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
              if (item[i]->color == searchColor){
                item[i]->printItem(i);
            /* we're saying keep following the pointers item[i] for every i and check their property called 
               color and when u find one that matches the serchColor, print it, make foundColor
              (which is initialized to false) true but don't end the loop continue until it reaches the last i*/
                foundColor = true;
               }
            }
          if (foundColor != true){
             cout<< "You don't have that hon... " << '\n'; }
            /* if foundColor never turns true, that means non of the objects that the item[i]s point to has a 
            color that matches the serch color*/
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
             if (item[i] -> isBottom()) {hasBottom = true;}
             /*What we're doing here is isTop is initialized to false in the clothingItem class which is the design that 
             both the top and bottom classses inherited. However, it is re-initialized to true specifically in the top class because 
             the function is virtual and so can be overriden by the child classes so it will be true if the object is found 
             in the top class but will continue to be false if not. We also declared inside the if statement that
             if it is true, then the bool variable 'hasTop' which is also initialized to be false will become true so
             if has top becomes true for any of the objects that means a top is found. same goes for bottom */
          }
          if (hasTop == false || hasBottom == false){
              cout << "Are you comfortable with being only partially clothed? Yea didn't think so";
              return;
            }

          do { topIndex = rand() % itemCount;}
          // this means generate a random number less than itemCount as a topIndex
          while
            (!item[topIndex]-> isTop());
          item[topIndex]-> printItem(topIndex);
          /* this means keep the loop going as long as item[topIndex] doesn't point to an object that makes isTop 
          true aka that is found in the class top. And when u do, end the loop and print the object based on the print function*/
          do { bottomIndex = rand() % itemCount;
         }
          while
            (!item[bottomIndex]-> isBottom());
          item[bottomIndex]-> printItem(bottomIndex);
          // the exact same thing here
   }
}
}

