/*
Michael Svoren
9/30/19
EECS 560
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

// template <typename t>
// bool BinarySearchTree<t>::Delete(t value)
// {
//     if (m_root == nullptr || !searchElement(value))
//     {
//         return false;
//     }
//
//     if (m_root -> getValue() == value)
//     {
//       if (m_root -> getRight() == nullptr && m_root -> getLeft() == nullptr)
//       {
//         delete m_root;
//         m_root = nullptr;
//         m_numNodes--;
//         return true;
//       }
//       else if (m_root -> getRight() != nullptr && m_root -> getLeft() != nullptr)
//       {
//         t min = findMinRight(m_root -> getRight());
//         //deleteMin(m_root, min);
//         if (leaf(min))
//         {
//           deleteLeaf(m_root, min);
//         }
//         else deleteHelper(m_root, findNodeToRemove(m_root->getRight(), min));
//         Node<t>* n = new Node<t>(min, m_root -> getLeft(), m_root -> getRight());
//         delete m_root;
//         m_root = n;
//         return true;
//        }
//        else if (m_root -> getRight() != nullptr)
//        {
//          Node<t>* temp = m_root -> getRight();
//          delete m_root;
//          m_root = temp;
//          return true;
//        }
//        else
//        {
//          Node<t>* temp = m_root -> getLeft();
//          delete m_root;
//          m_root = temp;
//          return true;
//        }
//     }
//
//     //delete if it is a leaf
//     if (leaf(value))
//     {
//         m_numNodes--;
//         return deleteLeaf(m_root, value);
//     }
//
//     if (deleteHelper(m_root, findNodeToRemove(m_root, value)))
//     {
//         m_numNodes--;
//         return true;
//     }
//     return false;
// }
//
// template< typename t>
// bool BinarySearchTree<t>::deleteLeaf(Node<t>* root, t value)
// {
//     if (root == nullptr)
//     {
//         return false;
//     }
//     //check left and right
//     if (root -> getRight() -> getValue() == value)
//     {
//         delete root -> getRight();
//         root -> setRight(nullptr);
//         return true;
//     }
//     else if (root -> getLeft() -> getValue() == value)
//     {
//         delete root -> getLeft();
//         root -> setLeft(nullptr);
//         return true;
//     }
//
//     if (root -> getValue() > value)
//     {
//         return deleteLeaf(root -> getLeft(), value);
//     }
//     else return deleteLeaf(root -> getRight(), value);
// }
//
// template <typename t>
// //cannot delete the root node here
// bool BinarySearchTree<t>::deleteMin(Node<t>* root, t value)
// {
//     if (root == nullptr) return false;
//
//     //since the node to delete is a min, it will only have a right subtree
//     if (root -> getLeft() != nullptr && root -> getLeft() -> getValue() == value)
//     {
//       Node<t>* temp = root ->getLeft()->getRight();
//       delete root -> getLeft();
//       root -> setLeft(temp);
//       return true;
//     }
//     else if (root -> getRight() != nullptr && root -> getRight() -> getValue() == value)
//     {
//       Node<t>* temp = root ->getRight()->getRight();
//       delete root -> getLeft();
//       root -> setRight(temp);
//       return true;
//     }
//
//     if (root -> getValue() > value)
//     {
//       return deleteMin(root-> getLeft(), value);
//     }
//     else return deleteMin(root ->getRight(), value);
//
//     // if (root -> getRight() -> getLeft() == nullptr)
//     // {
//     //     Node<t>* rightOfDelete = root -> getLeft() -> getRight();
//     //     delete root -> getLeft();
//     //     root -> setLeft(rightOfDelete);
//     //     return true;
//     // }
//     // return deleteMin(root -> getLeft(), value);
// }
//
//
// template <typename t>
// bool BinarySearchTree<t>::deleteHelper(Node<t>* root, Node<t>* nodeToRemove)
// {
//     if (root == nullptr)
//     {
//         return false;
//     }
//
//     if (root -> getRight() == nodeToRemove)
//     {
//         //already checked for case that this is a leaf
//         //case: 2 children
//         if (nodeToRemove->getLeft() != nullptr && nodeToRemove -> getRight() != nullptr)
//         {
//             t min = findMinRight(nodeToRemove -> getRight());
//             // deleteMin(nodeToRemove, min);
//             if (leaf(min))
//             {
//               deleteLeaf(nodeToRemove, min);
//             }
//             else deleteHelper(nodeToRemove, findNodeToRemove(nodeToRemove->getRight(), min));
//             Node<t>* n = new Node<t>(min, nodeToRemove -> getLeft(), nodeToRemove -> getRight());
//             delete nodeToRemove;
//             root -> setRight(n);
//             return true;
//         }
//         //case 1 left child
//         else if (nodeToRemove->getLeft() != nullptr)
//         {
//             Node<t>* left = nodeToRemove -> getLeft();
//             delete nodeToRemove;
//             root -> setRight(left);
//             return true;
//         }
//         //case 1 right child
//         else if (nodeToRemove->getRight() != nullptr)
//         {
//             Node<t>* right = nodeToRemove -> getRight();
//             delete nodeToRemove;
//             root -> setRight(right);
//             return true;
//         }
//         else
//         {
//             std::cout << "Error, unexpected case\n";
//             return false;
//         }
//     }
//     else if (root -> getLeft() == nodeToRemove)
//     {
//         //already checked for case that this is a leaf
//         //case: 2 children
//         if (nodeToRemove->getLeft() != nullptr && nodeToRemove -> getRight() != nullptr)
//         {
//             t min = findMinRight(nodeToRemove -> getRight());
//             //deleteMin(nodeToRemove, min);
//             if (leaf(min))
//             {
//               deleteLeaf(nodeToRemove, min);
//             }
//             else deleteHelper(nodeToRemove, findNodeToRemove(nodeToRemove->getRight(), min));
//
//             Node<t>* n = new Node<t>(min, nodeToRemove -> getLeft(), nodeToRemove -> getRight());
//             delete nodeToRemove;
//             root -> setLeft(n);
//             return true;
//         }
//         //case 1 left child
//         else if (nodeToRemove->getLeft() != nullptr)
//         {
//           std::cout << "one left child\n";
//             Node<t>* left = nodeToRemove -> getLeft();
//             delete nodeToRemove;
//             root -> setLeft(left);
//             return true;
//         }
//         //case 1 right child
//         else if (nodeToRemove->getRight() != nullptr)
//         {
//             Node<t>* right = nodeToRemove -> getRight();
//             delete nodeToRemove;
//             root -> setLeft(right);
//             return true;
//         }
//         else
//         {
//             std::cout << "Error, unexpected case\n";
//             return false;
//         }
//     }
//     else
//     {
//         if (root -> getValue() > nodeToRemove -> getValue())
//         {
//             return deleteHelper(root ->getLeft(), nodeToRemove);
//         }
//         else
//         {
//             return deleteHelper(root ->getRight(), nodeToRemove);
//         }
//     }
// }

template <typename t>
Node<t>* BinarySearchTree<t>::Delete1(Node<t>* root, t value)
{
  if (root == nullptr)
  {
    return nullptr;
  }

  if (root -> getValue() > value)
  {
    return Delete1(root -> getLeft(), value);
  }
  else if (root -> getValue() < value || root -> getValue() == value && !leaf(value))
  {
    return Delete1(root -> getRight(), value);
  }

  if (root -> getLeft() != nullptr & root -> getRight() != nullptr)
  {
    //FIXME CHECK IF LEAF
    Node<t>* minVal = findMinNodeRight(root);
    root -> setValue(minVal -> getValue);
    root -> setRight(Delete1(root->getRight());
  }
  else if (root -> getLeft() == nullptr)
  {
    Node<t>* temp = root -> getRight();
    delete temp;
    return temp;
  }
  else if (root -> getRight() == nullptr)
  {
    Node<t>* temp = root -> getLeft();
    delete temp;
    return temp;
   }
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
Node<t>* BinarySearchTree<t>::findNodeToRemove(Node<t>* root, t value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root -> getValue() == value)
    {
        return root;
    }

    if (root -> getValue() > value)
    {
        return findNodeToRemove(root -> getLeft(), value);
    }
    else return findNodeToRemove(root -> getRight(), value);
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
