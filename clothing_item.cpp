
#include <iostream>
#include "clothing_item.h"


namespace closet {

void clothingItem:: printItem(int i){
   cout << "#" << i + 1 << " ";
    cout << color << " " ;
    cout << type << " - ";
    cout << "ideal for " << occasion << '\n';
}
}