/*
Michael Svoren
9/30/19
EECS 560
Implementation file for the Executive class

*/
#include <iostream>
#include <fstream>
#include <string>

#include "BinarySearchTree.h"
#include "Executive.h"

Executive::Executive(std::string filePath)
{
    bTree = new BinarySearchTree<char>();
   std::ifstream reader;
   reader.open(filePath);
   if (reader)
   {
       char input =0;
       std::cout << "data.txt: ";
      while (reader >> input)
      {
         bTree ->addItem(input);
         std::cout << input << " ";
      }
      std::cout << std::endl;
      reader.close();
   }
   else
   {
      throw std::runtime_error("Unable to read file");
   }
}

void Executive::run()
{
   int userInput = 0;
   do
   {
      userInput = printOptionsAndGetUserInput();
      callFunctionFromUserInput(userInput);
   }
   while (userInput != 11);
}

int Executive::printOptionsAndGetUserInput()
{
   std::cout << "\nChoose one operation from the options below:\n";
   std::cout << "1. AddItem\n2. Delete\n3. Leaf\n4. PrintLeaf\n5. PrintTreeHeight\n6. PreOrder\n7. PostOrder\n8. InOrder\n9. LevelOrder\n10. SearchItem\n11. Exit\n";
   int userInput = 0;
   while (userInput < 1 || userInput > 11)
   {
      std::cin >> userInput;

      if (std::cin.fail() || userInput < 1 || userInput > 11)
      {
         std::cout << "Please enter an integer value between 1 and 11.\n";
          std::cin.clear();
          std::cin.ignore(1000, '\n');
      }
   }
   std::cout << '\n';
   return userInput;
}

void Executive::callFunctionFromUserInput(int userInput)
{
   if (userInput == 1)
   {
       std::cout << "Please enter the value to add to the tree: ";
        char val = 0;
        std::cin >> val;
        if (!std::cin.good())
        {
            std::cout << "You must enter a char\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            return;
        }

        if (bTree->addItem(val))
        {
            std::cout << "Value inserted successfully!\n";
        }
        else
        {
            std::cout << "Failed to insert value\n";
        }
   }
   else if (userInput == 2)
   {
        std::cout << "Please enter the value to delete from the tree: ";
        char val = 0;
        std::cin >> val;
        if (!std::cin.good())
        {
            std::cout << "You must enter a char\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            return;
        }

       try
       {
            if (bTree -> Delete(val))
            {
                std::cout << "Successfully deleted " << val << " from tree\n";
            }
            else {
                std::cout << "Delete failed: character not found\n";
            }
       }
       catch(const std::exception& e)
       {
           std::cout << "Could not delete node\n";
       }

   }
   else if (userInput == 3)
   {
       char val = 0;
       std::cout << "Please enter the value to test as a leaf node: ";
       std::cin >> val;
       if (bTree -> leaf(val))
       {
           std::cout << "The node containing " << val << " is a leaf node\n";
       }
       else
       {
           std::cout << val << " is not a leaf node\n";
       }
   }
   else if (userInput == 4)
   {
       bTree -> printLeafs();
   }
   else if (userInput == 5)
   {
       bTree ->  printTreeHeight();
   }
   else if (userInput == 6)
   {
       bTree ->  preOrder();
   }
   else if (userInput == 7)
   {
       bTree ->  postOrder();
   }
   else if (userInput == 8)
   {
       bTree ->  inOrder();
   }
   else if (userInput == 9)
   {
       bTree ->  levelOrder();
   }
   else if (userInput == 10)
   {
        std::cout << "Please enter the to search for: ";
        char val = 0;
        std::cin >> val;
        if (!std::cin.good())
        {
            std::cout << "You must enter a char\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            return;
        }
       if (bTree -> searchElement(val))
       {
           std::cout << val << " was found in the binary search tree\n";
       }
       else
       {
           std::cout << val << " was not found in the binary search tree\n";
       }
   }
}

Executive::~Executive()
{
    delete bTree;
}
