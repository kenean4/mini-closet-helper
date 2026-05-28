
#ifndef CLOSET_H
#define CLOSET_H

#include <string>
#include "clothing_item.h"

using namespace std;
namespace closet {

const int max_num = 20;
    
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