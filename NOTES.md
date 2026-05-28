MINI CLOSET HELPER - NOTES
===========================

CLOSET.H
--------

NAMESPACE:
★ the namespace isn't really necessary for this program but its a good habit for bigger programs where two
or more functions or variables might have the same name but different purpose.
★ Namespaces also help when combining multiple libraries where two different libraries might have a
function with the same name — the namespace separates them so the compiler knows which one you mean
e.g closet::search() vs library::search()

CLASS clothingItem:
★ we include all the variables(properties) and functions(methods) that are specific to each clothingItem
in this class.
★ this class has no objects actually stored in it because whenever an object is created in the addItem
function, we made sure that the only 2 options of storage are new Top() and new Bottom() so no object
ever enters this class.
★ It's just a blueprint of the structure for the top and bottom classes.

virtual bool isTop() and virtual bool isBottom():
★ these are initialized to false here as the default.
★ They are virtual meaning child classes can override them.
★ We initialize them to false here because we don't want every item to claim it's a top or bottom
by default — only the specific child class should return true for its own method.

CLASS Top and Bottom:
★ Both top and bottom classes inherit the structure of the clothingItem class but override isTop and
isBottom to return true respectively.
★ They inherit type, color, occasion and printItem automatically from clothingItem.

clothingItem* item[max_num] inside class Closet:
★ This means we created an array inside this class called item which holds 20 (max_num) slots.
★ what do we store in those slots? things of the type clothingItem*.
★ what type of things are those? well clothingItem tells us that they are things that have the
properties and methods of the clothingItems and the '*' tells us that those things aren't the actual
objects but the pointers to those objects that have the properties of the clothingItem.
★ And since we know that we store nothing in clothingItem (we chose not to) the only objects with
those properties are the ones in the top and bottom classes hence the things stored in the item array
are pointers that point to objects in the top or bottom classes.
★ This array is also the link between the closet and the clothing item and its children classes.

CLASS Closet:
★ we include all the functions and declared variables that aren't specific to each individual clothing
item in this class.


CLOSET.CPP
----------

Closet::addItem:
★ Closet::*a function xyz* means the function xyz which is found in the class Closet and we do that
so that the function can access the variables declared in the class without listing them all in its parameter.

tempoType variable:
★ This is a temporary variable created to store the type entered by the console.
★ It is needed because the object where the type will be permanently stored cannot be created yet as
it is the type that determines on which class the object will be created, Top or Bottom.

new Top() / new Bottom():
★ new is what actually rents memory and creates the object.
★ Top or Bottom is where it is created and item[itemCount] is where its address is stored since item
is the array of pointers.

item[itemCount]->type = tempoType:
★ This is where we place the type into the object.
★ We use -> because item[itemCount] is a pointer — the arrow means follow the pointer to the address
of the object it points to and set its property.

-> operator:
★ We say '->' because item[itemCount] is a pointer found in the array of pointers called item so the
arrow means follow the pointer to the address of the object it points to and access or set the property
of the object.
★ The actual object is found either in the class Top or Bottom.

Closet::searchItem:
★ we're saying keep following the pointers item[i] for every i and check their property called color
and when you find one that matches the searchColor, print it, make foundColor (which is initialized
to false) true but don't end the loop, continue until it reaches the last i.
★ if foundColor never turns true, that means none of the objects that the item[i]s point to has a
color that matches the search color.

Closet::suggestOutfit — for loop:
★ isTop is initialized to false in the clothingItem class which is the design that both the top and
bottom classes inherited.
★ However, it is re-initialized to true specifically in the top class because the function is virtual
and so can be overridden by the child classes so it will be true if the object is found in the class
Top but will continue to be false if not.
★ We also declared inside the if statement that if it is true, then the bool variable 'hasTop' which
is also initialized to be false will become true so if hasTop becomes true for any of the objects
that means a top is found. same goes for bottom.

Closet::suggestOutfit — do while loops:
★ 'rand() % itemCount' means generate a random number less than itemCount as a topIndex.
★ 'while(!item[topIndex]->isTop())' means keep the loop going as long as item[topIndex] doesn't
point to an object that makes isTop true aka that is found in the class Top.
★ And when you find one, end the loop and print the object based on the print function.
★ Same logic applies for the bottom loop.


MAIN.CPP
--------

Closet myCloset:
★ Here, we are creating an object called myCloset based on the structure of the class Closet because
the class itself is just a blueprint and doesn't actually hold any data or do anything — it's just
a design.
★ The object is the actual storage.

myCloset.addItem():
★ the myCloset.addItem does the same thing as Closet::addItem but Closet::addItem was defining which
class the function belongs to, where the logic lives and what it can access.
★ myCloset.addItem() is the actual call telling the compiler to go to the object myCloset and call
the function addItem to do its job.
★ polymorphism= taking the same function from a parent class and giving it different characteristics on the children classes like the isTop and isBottom functions

DATA PERSISTENCE
----------------

STREAMS:
★ cin is a stream that delivers data from the keyboard
★ cout is a stream that delivers data to the console
★ ifstream is a stream that delivers data from a file
★ ofstream is a stream that delivers data to a file
★ stringstream is the same idea but the data comes from a string instead

getline(file, nextLine):
★ gets the next line from the file and stores it in nextLine
★ remembers where it left off automatically so each call gets the next line
★ when the file runs out of lines it returns false and the while loop stops

getline(parser, typ, ','):
★PARSING= splitting a line into separate values
★ gets everything from the stringstream until it hits a comma and stores it in typ
★ the third argument, the comma, is the delimiter — it tells getline where to stop reading
★ the next getline continues from where the previous one ended which is right after the comma
★ the delimiter is consumed and discarded automatically — it doesn't appear in what gets stored

saveCloset:
★ opens closet.txt and wipes it completely then rewrites all items from scratch
★ the items aren't lost when the file is wiped because they still exist on the heap
★ the for loop just follows each pointer and writes the data of the object it points to into the file

loadCloset at startup:
★ before the user sees the menu, the program reads the file and fills up item[] and itemCount
with all the previously saved clothes so the data is already there when the user does anything
★ itemCount starts at 0 when the program restarts but loadCloset increments it as it loads
each item so it fixes itself automatically during loading

stringstream parser(nextLine):
★ creates a stringstream object loaded with the contents of nextLine
★ lets you read from a string piece by piece the same way you read from a file
★ must be inside the while loop so it gets a fresh line each time