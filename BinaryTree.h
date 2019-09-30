/*
Michael Svoren
8/30/19
EECS 560
*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"

template <typename t>
class BinaryTree
{
    private:
        Node<t>* m_root;
        int m_numNodes;
        int getTreeHeight() const;
        bool findElement(t val, Node<t>* root) const;
        int getLevel(t val, Node<t>* root, int level) const;
        bool addItemHelper(t value, Node<t>* root, int treeHeight, int currentLevel);
        void addToFarthestLeft(t value, Node<t>* root);
        void printLeafsHelper(Node<t>* root) const;
        int getTreeHeightHelper(Node<t>* root, int h) const;
        bool deleteHelper(Node<t>* root, int treeHeight, int currentLevel);
        Node<t>* getLastNode(Node<t>* root, int treeHeight, int currentLevel);
        void printPreOrder(Node<t>* root) const;
        void printPostOrder(Node<t>* root) const;
        void printInOrder(Node<t>* root) const;
        void printLevelOrder(Node<t>* root, int targetLevel, int currentLevel) const;
        Node<t>* isLeafHelper(Node<t>* root, t value);

    public:
        bool isFull() const;
        bool addItem(t value);
        t Delete();
        bool leaf(t value);
        void printLeafs() const;
        void printTreeHeight() const;
        void preOrder() const;
        void postOrder() const;
        void inOrder() const;
        void levelOrder() const;

        BinaryTree();
        ~BinaryTree();
};
#include "BinaryTree.cpp"
#endif