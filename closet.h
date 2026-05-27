#include <string>

using namespace std;

#ifndef CLOSET_H
#define CLOSET_H



namespace closet {
    /*the namespace isn't really necessary for this program but its a good habit for bigger programs where two 
    or more functions or variables might have the same name but different purpose*/
    const int max_num = 20;
    
class clothingItem {
public:
string type;
string color;
string occasion;

/* we include all the variables(properties) and functions(methods) that are specific to each 
clothingItem in this class*/

virtual bool isTop() {return false;}
virtual bool isBottom() {return false;}
void printItem(int i);

/* this class is empty no object is actually stored here because whenever an object is created in the addItem
 function, we made sure that the only 2 options of storage are new top() and new bottom() so no object ever enters this class.
 It's just a blueprint of the structure for the top and bottom classes*/
};

class Top: public clothingItem {
public: bool isTop() {return true;} 
};

class Bottom: public clothingItem {
public: bool isBottom() {return true;}
};

/*Both top and bottom classes inherit the structure of the clothingItem clase but add their own property by
re-initializing isTop and isBottom to true respectively */

class Closet{
public:
int itemCount=0;
clothingItem* item [max_num];
/*This means we created an array insde this class called item which holds 20 (max_num) slots(shelves). what do we store in those slots?
things of the type clothingItem*. what type of things are those? well clothIng item tells us that they are thing that 
have the properties and methods of the clothingItems and the '*' tells us that those things aren't the actual objects
but the pointers to those objects that have the properties of the clothingItem. And since we know that we store nth in 
the clothingItems(we chose not to) the only objects with those properties are the ones in the top and bottom classes hence the things
stored in the item array are pointers that point to objects in the top or bottom classes. This array is also the 
link between the closet and the clothing item and its children classes.   */
void addItem();
void viewItem();
void searchItem(); 
void suggestOutfit();

// we include all the functions and declared variables that aren't specific to each clothing items in this class

};
}


#endif