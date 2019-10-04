/*
Michael Svoren
9/30/19
EECS 560
Header file for the Executive class

*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>

#include "BinarySearchTree.h"

class Executive {
    private:
        BinarySearchTree<char>* bTree;
        int printOptionsAndGetUserInput();
        void callFunctionFromUserInput(int userInput);

    public:
        Executive(std::string filePath);
        void run();
        ~Executive();
};
#endif
