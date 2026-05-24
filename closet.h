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

void printItem(int i);
};

class Closet{
public:
clothingItem item [max_num];
void addItem();
void viewItem();
void searchItem(); 
void suggestOutfit();
};
}


#endif