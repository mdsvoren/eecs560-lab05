/*
Michael Svoren
9/30/19
EECS 560
Node.h - Header file for Node class. Each node points to the next node, previous node, and holds an int
*/
#ifndef NODE_H
#define NODE_H

template <typename t>
class Node
{
    private:
        Node<t>* m_left;
        Node<t>* m_right;
        t m_value;

    public:
        bool setRight(Node<t>* nextRight);
        bool setLeft(Node<t>* nextLeft);
        bool setValue(t value);

        Node<t>* getRight() const;
        Node<t>* getLeft() const;
        t getValue() const;

        bool isLeaf() const;

        Node(t value);
        Node(t value, Node<t>* nextLeft, Node<t>* nextRight);
};
#include "Node.cpp"
#endif