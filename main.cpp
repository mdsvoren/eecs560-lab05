/*
Michael Svoren
9/30/19
EECS 560
*/
#include <iostream>
#include <string>

#include "Executive.h"
#include "BinarySearchTree.h"

int main()
{
    std::cout << "Starting...\n";
    try
   {
      Executive e1 = Executive("data.txt");
      e1.run();
   }
   catch(std::runtime_error& e)
   {
      std::cout << "Unable to open specified file. Please restart program to try again.\n";
   }


   // BinarySearchTree<char>* bst = new BinarySearchTree<char>();

   // bst -> addItem('f');
   // bst -> printTreeHeight();
   // bst -> printLeafs();
   
   // bst -> addItem('b');
   // bst -> printTreeHeight();
   // bst -> printLeafs();

   // bst -> addItem('g');
   // bst -> printTreeHeight();
   // bst -> printLeafs();

   // bst -> addItem('d');
   // bst -> printTreeHeight();
   // bst -> printLeafs();

   std::cout << "\nExiting program\n";
}