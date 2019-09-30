#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>

#include "BinaryTree.h"

class Executive {
    private:
        BinaryTree<int>* bTree;
        int printOptionsAndGetUserInput();
        void callFunctionFromUserInput(int userInput);

    public:
        Executive(std::string filePath);
        void run();
        ~Executive();
};
#endif