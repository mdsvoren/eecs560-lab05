/*
Michael Svoren
9/30/19
EECS 560
Implementation file for the BST
*/
#include <string>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "BinarySearchTree.h"
#include "Node.h"

template <typename t>
BinarySearchTree<t>::BinarySearchTree()
{
    m_root = nullptr;
    m_numNodes = 0;
}
template <typename t>
BinarySearchTree<t>::~BinarySearchTree()
{
    while (m_root != nullptr)
    {
         Delete(m_root -> getValue());
    }
}


template <typename t>
bool BinarySearchTree<t>::addItem(t value)
{
        m_numNodes++;
    if (m_root == nullptr)
    {
        Node<t>* n = new Node<t>(value, nullptr, nullptr);
        m_root = n;
        return true;
    }
    else
    {
        return addItemHelper(value, m_root);
    }


}


template <typename t>
bool BinarySearchTree<t>::addItemHelper(t value, Node<t>* root)
{
    //this may not be needed
    if (root == nullptr)
    {
        return false;
    }
    //go left
    if (root -> getValue() > value)
    {
        //insert node if there is no left child
        if (root -> getLeft() == nullptr)
        {
            Node<t>* n = new Node<t>(value, nullptr, nullptr);
            root -> setLeft(n);
            return true;
        }
        //else continue left
        else
        {
            return addItemHelper(value, root -> getLeft());
        }
    }
    else
    {
        //insert node if there is no right child
        if (root -> getRight() == nullptr)
        {
            Node<t>* n = new Node<t>(value, nullptr, nullptr);
            root -> setRight(n);
            return true;
        }
        //else continue right
        else
        {
            return addItemHelper(value, root -> getRight());
        }
    }
}

template <typename t>
bool BinarySearchTree<t>::searchElementHelper(t val, Node<t>* root) const
{
    if (root == nullptr)
    {
        return false;
    }

    if (root -> getValue() == val)
    {
        return true;
    }

    if (root -> getValue() > val)
    {
        return searchElementHelper(val, root -> getLeft());
    }
    else
    {
        return searchElementHelper(val, root -> getRight());
    }
}

template <typename t>
bool BinarySearchTree<t>::searchElement(t val) const
{
    return searchElementHelper(val, m_root);
}


template <typename t>
bool BinarySearchTree<t>::Delete(t value)
{
    if (m_root == nullptr || !searchElement(value))
    {
        return false;
    }


        m_root = DeleteHelper(m_root, value);
        m_numNodes--;
        return true;

}

template <typename t>
Node<t>* BinarySearchTree<t>::DeleteHelper(Node<t>* root, t value)
{
    if (root == nullptr) return root;

    //if this is the correct value, and it's the only existing value, or else if it is the leaf
    if (root -> getValue() == value && (!leaf(value) || (root ->getLeft() == nullptr && root -> getRight() == nullptr)))
    {
        if (root -> getLeft() != nullptr && root -> getRight()!= nullptr)
        {
            t tempMin = findMinRight(root -> getRight());
            root -> setValue(tempMin);
            root -> setRight(DeleteHelper(root -> getRight(), tempMin));
        }
        else if (root -> getRight() == nullptr)
        {
            Node<t>* temp = root -> getLeft();
            delete root;
            return temp;
        }
        else
        {
            Node<t>* temp = root -> getRight();
            delete root;
            return temp;
        }
    }
    //go left
    else if (value < root -> getValue())
    {
        root -> setLeft(DeleteHelper(root -> getLeft(), value));
    }
    //go right (also includes case that we're looking for leaf)
    else if (value >= root -> getValue())
    {
        root -> setRight(DeleteHelper(root -> getRight(), value));
    }
   return root;
}


template <typename t>
t BinarySearchTree<t>::findMinRight(Node<t>* root)
{
    if (root -> getLeft() == nullptr)
    {
        return root->getValue();
    }
    return findMinRight(root -> getLeft());
}

template <typename t>
bool BinarySearchTree<t>::leaf(t value)
{
    return isLeafHelper(m_root, value);
}

template <typename t>
bool BinarySearchTree<t>::isLeafHelper(Node<t>* root, t value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root -> getValue() == value && root -> getLeft() == nullptr && root -> getRight() == nullptr)
    {
        return true;
    }

    if (root -> getValue() > value)
    {
        return isLeafHelper(root -> getLeft(), value);
    }
    else
    {
        return isLeafHelper(root -> getRight(), value);
    }
}

template <typename t>
void BinarySearchTree<t>::printLeafs() const
{
    if (m_root == nullptr)
    {
        std::cout << "Tree is empty\n";
    }
    std::cout << "The leaf nodes are: ";
    printLeafsHelper(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinarySearchTree<t>::printLeafsHelper(Node<t>* root) const
{
    if (root == nullptr)
    {
        return;
    }
    if (root -> getLeft() == nullptr && root -> getRight() == nullptr)
    {
        std::cout << root -> getValue() << " ";
        return;
    }
    printLeafsHelper(root->getLeft());
    printLeafsHelper(root -> getRight());

}

template <typename t>
void BinarySearchTree<t>::printTreeHeight() const
{
    std::cout << "The height of the tree is " << getTreeHeight() << std::endl;
}

template <typename t>
int BinarySearchTree<t>::getTreeHeight() const
{
    return getTreeHeightHelper(m_root, -1);
}

template <typename t>
int BinarySearchTree<t>::getTreeHeightHelper(Node<t>* root, int h) const
{
    if (root == nullptr) return h;
    return std::max(getTreeHeightHelper(root->getRight(), h+1), getTreeHeightHelper(root->getLeft(), h+1));
}

template <typename t>
void BinarySearchTree<t>::preOrder() const
{
    std::cout << "Printing tree in Pre-Order: ";
    printPreOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinarySearchTree<t>::printPreOrder(Node<t>* root) const
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->getValue() << " ";
    printPreOrder(root -> getLeft());
    printPreOrder(root -> getRight());
}

template <typename t>
void BinarySearchTree<t>::postOrder() const
{
    std::cout << "Printing tree in Post-Order: ";
    printPostOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinarySearchTree<t>::printPostOrder(Node<t>* root) const
{
    if (root == nullptr)
    {
        return;
    }
    printPostOrder(root -> getLeft());
    printPostOrder(root -> getRight());
    std::cout << root->getValue() << " ";
}

template <typename t>
void BinarySearchTree<t>::inOrder() const
{
    std::cout << "Printing tree in In-Order: ";
    printInOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinarySearchTree<t>::printInOrder(Node<t>* root) const
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root -> getLeft());
    std::cout << root->getValue() << " ";
    printInOrder(root -> getRight());
}

template <typename t>
void BinarySearchTree<t>::levelOrder() const
{
    std::cout << "Printing tree in Level-Order: ";
    int tHeight = getTreeHeight();
    for (int i = 0; i<= tHeight; i++)
    {
        printLevelOrder(m_root, i, 0);
    }
    std::cout << std::endl;

}

template <typename t>
void BinarySearchTree<t>::printLevelOrder(Node<t>* root, int targetLevel, int currentLevel) const
{
    if (root == nullptr || currentLevel > targetLevel)
    {
        return;
    }
    if (currentLevel == targetLevel)
    {
        std::cout << root ->getValue() << " ";
    }
    printLevelOrder(root -> getLeft(), targetLevel, currentLevel + 1);
    printLevelOrder(root -> getRight(), targetLevel, currentLevel + 1);
}
