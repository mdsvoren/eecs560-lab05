/*
Michael Svoren
8/30/19
EECS 560
Node.cpp - Implementation for Node class. Each node points to the next node, previous node, and holds an int
*/
#include <string>
#include <stdexcept>

#include "Node.h" //maybe take this out?

template <typename t>
Node<t>::Node(t val)
{
    m_value = val;
}

template <typename t>
Node<t>::Node(t val, Node<t>* nextLeft, Node<t>* nextRight)
{
    m_value = val;
    m_left = nextLeft;
    m_right = nextRight;
}

template <typename t>
Node<t>* Node<t>::getLeft() const
{
    return m_left;
}

template <typename t>
Node<t>* Node<t>::getRight() const
{
    return m_right;
}

template <typename t>
t Node<t>::getValue() const
{
    return m_value;
}

template<typename t>
bool Node<t>::setRight(Node<t>* nextRight)
{
    m_right = nextRight;
    return true;
}

template<typename t>
bool Node<t>::setLeft(Node<t>* nextLeft)
{
    m_left = nextLeft;
    return true;
}

template<typename t>
bool Node<t>::setValue(t value)
{
    return true;
}