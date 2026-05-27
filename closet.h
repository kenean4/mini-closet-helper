#include <string>

using namespace std;

#ifndef CLOSET_H
#define CLOSET_H


namespace closet {

const int max_num = 20;
    
class clothingItem {
public:
string type;
string color;
string occasion;

virtual bool isTop() {return false;}
virtual bool isBottom() {return false;}
void printItem(int i);
};

class Top: public clothingItem {
public: bool isTop() {return true;} 
};

class Bottom: public clothingItem {
public: bool isBottom() {return true;}
};

class Closet{
public:
int itemCount=0;

clothingItem* item [max_num];

void addItem();
void viewItem();
void searchItem(); 
void suggestOutfit();
void loadCloset();
void saveCloset();
};
}

#endif