#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.h"
#include "Executive.h"

Executive::Executive(std::string filePath)
{
    bTree = new BinaryTree<int>();
   std::ifstream reader;
   reader.open(filePath);
   if (reader)
   {
       int input =0;
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
   std::cout << "1. IsFull\n2. AddItem\n3. Delete\n4. Leaf\n5. PrintLeaf\n6. PrintTreeHeight\n7. PreOrder\n8. PostOrder\n9. InOrder\n10. LevelOrder\n11. Exit\n";
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
       std::cout << "IsFull: ";
       if (bTree->isFull())
       {
           std::cout << "True\n";
       }
       else
       {
           std::cout << "False\n";
       }
       
   }
   else if (userInput == 2)
   {
       std::cout << "Please enter the value to add to the tree: ";
        int val = 0;
        std::cin >> val;
        if (!std::cin.good())
        {
            std::cout << "You must enter an int\n";
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
            std::cout << "Failed to insert value - already present in tree\n";
        }
   }
   else if (userInput == 3)
   {
       try
       {
           int val = bTree -> Delete();
            std::cout << "Successfully deleted the last value, " << val << ", from tree\n";
       }
       catch(const std::exception& e)
       {
           std::cout << "Could not delete node - tree is empty\n";
       }
       
   }
   else if (userInput == 4)
   {
       int val = 0;
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
   else if (userInput == 5)
   {
       bTree -> printLeafs();
   }
   else if (userInput == 6)
   {
       bTree ->  printTreeHeight();
   }
   else if (userInput == 7)
   {
       bTree ->  preOrder();
   }
   else if (userInput == 8)
   {
       bTree ->  postOrder();
   }
   else if (userInput == 9)
   {
       bTree ->  inOrder();
   }
   else if (userInput == 10)
   {
       bTree ->  levelOrder();
   }
}

Executive::~Executive()
{
    delete bTree;
}