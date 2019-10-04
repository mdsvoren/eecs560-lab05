/*
Michael Svoren
9/30/19
EECS 560
*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"

template <typename t>
class BinarySearchTree
{
    private:
        Node<t>* m_root;
        int m_numNodes;
        int getTreeHeight() const;
        bool searchElementHelper(t val, Node<t>* root) const;
        bool addItemHelper(t value, Node<t>* root);
        void printLeafsHelper(Node<t>* root) const;
        int getTreeHeightHelper(Node<t>* root, int h) const;
        bool deleteHelper(Node<t>* root, Node<t>* nodeToRemove);
        void printPreOrder(Node<t>* root) const;
        void printPostOrder(Node<t>* root) const;
        void printInOrder(Node<t>* root) const;
        void printLevelOrder(Node<t>* root, int targetLevel, int currentLevel) const;
        bool isLeafHelper(Node<t>* root, t value);
        Node<t>* findNodeToRemove(Node<t>* root, t value);
        bool deleteMin(Node<t>* root, t value);
        t findMinRight(Node<t>* root);
        bool deleteLeaf(Node<t>* root, t value);
        Node<t>* Delete1(Node<t>* root, t value);

    public:
        bool addItem(t value);
        bool Delete(t value);
        bool leaf(t value);
        void printLeafs() const;
        void printTreeHeight() const;
        void preOrder() const;
        void postOrder() const;
        void inOrder() const;
        void levelOrder() const;
        bool searchElement(t value) const;

        BinarySearchTree();
        ~BinarySearchTree();
};
#include "BinarySearchTree.cpp"
#endif
