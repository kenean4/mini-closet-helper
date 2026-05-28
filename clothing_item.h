#ifndef CLOTHING_ITEM_H
#define CLOTHING_ITEM_H

#include <string>

using namespace std;

namespace closet {


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
}

#endif
