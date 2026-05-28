# Mini Closet Helper

A C++ command-line application that helps you manage your wardrobe.
Add clothing items, view your closet, search by color or occasion,
and get random outfit suggestions.

## Features

- Add clothing items with type, color, and occasion
- View all items in your closet
- Search items by color or occasion
- Get a random outfit suggestion (top + bottom)
- Data persistence — your closet is saved and reloaded automatically

## How to Run

**Compile:**
g++ main.cpp closet.cpp -o closet

**Run:**
.\closet

## Project Structure
mini_closet_helper/
├── main.cpp        # entry point, menu loop
├── closet.cpp      # class method definitions
├── closet.h        # class declarations
├── closet.txt      # auto-generated save file
└── NOTES.md        # personal learning notes

## Concepts Used

- Object Oriented Programming (classes, inheritance, polymorphism)
- Dynamic memory allocation (new, delete)
- File I/O (ofstream, ifstream, stringstream)
- Namespaces
- Virtual functions
- Pointers and references

## Clothing Types

**Tops:** hoodie, crewneck, jacket, t-shirt, shirt

**Bottoms:** skirt, jeans, cargo, shorts, sweatpants

## Notes

This project was built as a learning exercise while studying C++.
See NOTES.md for detailed explanations of every concept used.