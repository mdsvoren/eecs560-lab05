/*
Michael Svoren
8/30/19
EECS 560
*/
#include <string>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "BinaryTree.h" //maybe take this out?
#include "Node.h"

template <typename t>
BinaryTree<t>::BinaryTree()
{
    m_root = nullptr;
    m_numNodes = 0;
}
template <typename t>
BinaryTree<t>::~BinaryTree()
{
    while (m_numNodes>0)
    {
        Delete();
    }
}

template <typename t>
bool BinaryTree<t>::isFull() const
{
    if (m_root == nullptr) return false;
    return pow(2, getTreeHeight() + 1) - 1 == m_numNodes;
}

template <typename t>
bool BinaryTree<t>::addItem(t value)
{
    if (findElement(value, m_root))
    {
        return false;
    }
    if (m_root == nullptr)
    {
        m_root = new Node<t>(value, nullptr, nullptr);
        m_numNodes++;
        return true;
    }

    if (isFull())
    {
        addToFarthestLeft(value, m_root);
        m_numNodes++;
        return true;
    }

    int treeHeight = getTreeHeight();
    if(addItemHelper(value, m_root, treeHeight, 0))
    {
        m_numNodes++;
        return true;
    }
    else return false;
    /*
   
    -1. Check if overall tree is full, if so, insert on the farthest leeft spot
    0. get height of overall tree and pass it through
    1. recursively visit nodes and check if the level is equal to original tree height
        if yes, do nothing
        if no, check if it has a left and right subtree
            insert new node into one of these

*/
}

template <typename t>
void BinaryTree<t>::addToFarthestLeft(t value, Node<t>* root)
{
    if (root -> getLeft() == nullptr)
    {
        Node<t>* newNode = new Node<t>(value, nullptr, nullptr);
        root -> setLeft(newNode);
        return;
    }
    addToFarthestLeft(value, root -> getLeft());
}

template <typename t>
bool BinaryTree<t>::addItemHelper(t value, Node<t>* root, int treeHeight, int currentLevel)
{
    //if we are on the lowest level
    if (currentLevel == treeHeight)
    {
        return false;
    }

    if (root -> getLeft() == nullptr)
        {
            //insert left
            Node<t>* newNode = new Node<t>(value, nullptr, nullptr);
            root -> setLeft(newNode);
            return true;
        }
    if (root -> getRight() == nullptr)
        {
            //insret right
            Node<t>* newNode = new Node<t>(value, nullptr, nullptr);
            root -> setRight(newNode);
            return true;
        }

    if (addItemHelper(value, root -> getLeft(), treeHeight, currentLevel + 1)) return true;
    else return addItemHelper(value, root -> getRight(), treeHeight, currentLevel + 1);
}

template <typename t>
bool BinaryTree<t>::findElement(t val, Node<t>* root) const
{
    if (root == nullptr)
    {
        return false;
    }
    if (root -> getValue() == val)
    {
        return true;
    }
    
    return (findElement(val, root->getLeft()) || findElement(val, root ->getRight()));
}

template <typename t>
int BinaryTree<t>::getLevel(t val, Node<t>* root, int level) const
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root -> getValue() == val)
    {
        return level;
    }
    
    int left = getLevel(val, root->getLeft(), level+1);
    int right = getLevel(val, root ->getRight(), level+1);
    if (left > right )
    {
        return left;
    } else return right;
}

template <typename t>
t BinaryTree<t>::Delete()
{
    if (m_root == nullptr)
    {
        std::cout << "Tree is empty. Unable to delete item.\n";
        throw (std::runtime_error("Tree empty. Unable to delete item"));
    }

    int treeHeight = getTreeHeight();
    t val = getLastNode(m_root, treeHeight, 0) ->getValue();
    if (m_numNodes == 1)
    {
        delete m_root;
        m_root = nullptr;
    }
    else
    {
        deleteHelper(m_root, treeHeight, 0);
    }
    m_numNodes--;
    return val;
}

template <typename t>
bool BinaryTree<t>::deleteHelper(Node<t>* root, int treeHeight, int currentLevel)
{
    if (root == nullptr)
    {
        return false;
    }
   if (currentLevel == treeHeight-1)
   {
       if (root -> getRight() != nullptr)
       {
           delete root ->getRight();
           root -> setRight(nullptr);
           return true;
       }
       else if (root -> getLeft() != nullptr)
       {
           delete root ->getLeft();
           root -> setLeft(nullptr);
           return true;
       }
       else return false;
   }
   if (deleteHelper(root -> getRight(), treeHeight, currentLevel+1)) return true;
   return deleteHelper(root -> getLeft(), treeHeight, currentLevel+1);

}

template <typename t>
Node<t>* BinaryTree<t>::getLastNode(Node<t>* root, int treeHeight, int currentLevel)
{
    //this is for ease of readability
    if (root == nullptr)
    {
        return nullptr;
    }
    if (currentLevel == treeHeight)
    {
        return root;
    }

    Node<t>* right = getLastNode(root -> getRight(), treeHeight, currentLevel + 1);
    if (right != nullptr) return right;
    return getLastNode(root -> getLeft(), treeHeight, currentLevel + 1);

}

template <typename t>
bool BinaryTree<t>::leaf(t value)
{
    if (m_numNodes == 0) return false;
    Node<t>* temp = isLeafHelper(m_root, value);
    if (temp == nullptr) return false;
    if (temp -> getRight() == nullptr && temp -> getLeft() == nullptr) return true;
    else return false;

}

template <typename t>
Node<t>* BinaryTree<t>::isLeafHelper(Node<t>* root, t value)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root -> getValue() == value)
    {
        return root;
    }
    
    Node<t>* left = isLeafHelper( root->getLeft(), value);
    if (left != nullptr) return left;
    return isLeafHelper(root -> getRight(), value);
}

template <typename t>
void BinaryTree<t>::printLeafs() const
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
void BinaryTree<t>::printLeafsHelper(Node<t>* root) const
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
void BinaryTree<t>::printTreeHeight() const
{
    std::cout << "The height of the tree is " << getTreeHeight() << std::endl;
}

template <typename t>
int BinaryTree<t>::getTreeHeight() const
{
    return getTreeHeightHelper(m_root, -1);
}

template <typename t>
int BinaryTree<t>::getTreeHeightHelper(Node<t>* root, int h) const
{
    if (root == nullptr) return h;
    return std::max(getTreeHeightHelper(root->getRight(), h+1), getTreeHeightHelper(root->getLeft(), h+1));
}

template <typename t>
void BinaryTree<t>::preOrder() const
{
    std::cout << "Printing tree in Pre-Order: ";
    printPreOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinaryTree<t>::printPreOrder(Node<t>* root) const
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
void BinaryTree<t>::postOrder() const
{
    std::cout << "Printing tree in Post-Order: ";
    printPostOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinaryTree<t>::printPostOrder(Node<t>* root) const
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
void BinaryTree<t>::inOrder() const
{
    std::cout << "Printing tree in In-Order: ";
    printInOrder(m_root);
    std::cout << std::endl;
}

template <typename t>
void BinaryTree<t>::printInOrder(Node<t>* root) const
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
void BinaryTree<t>::levelOrder() const
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
void BinaryTree<t>::printLevelOrder(Node<t>* root, int targetLevel, int currentLevel) const
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