//BinarySearchTree.h
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BNode.h"
#include <iostream>
#include <algorithm>

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
		// Default constructor
	BinarySearchTree(const BinarySearchTree& otherBST);
		// Copy constructor
	~BinarySearchTree();
		//Destructor
	
	void deleteAll();
		//deletes all nodes in the tree
	const T& findMin() const;
		//finds the minimum value in the tree
	const T& findMax() const;
		//finds the maximum value in the tree
	bool find(T& x);
		//returns true if value is found within tree, 
		//otherwise returns false
	bool isEmpty() const;
		//returns true if the tree is empty
		//otherwise returns false
	void printInorderTraversal() const;
		//prints the tree using Inorder Traversal
	void printPostorderTraversal() const;
		//prints the tree using Postorder Traversal
	void printPreorderTraversal() const;
		//prints the tree using Preorder Traversal
	
	void insert(T& x);
		//inserts x into the tree
	int height() const;
		//returns the height of the entire tree
	void deleteNode(T& x);
		//deletes the object with the value x

	const BinarySearchTree& operator=(const BinarySearchTree& rhs);
		//overloaded assignment operator for BST
	
private:
	BNode<T> *root;
	int nodeCount;

	void insert( T& x, BNode<T> * & t);
		//internal method to insert an item in a subtree to its rightful place
	void remove( T& x, BNode<T> * & t);
		//internal method to remove an item from a subtree and relinks where appropriate
	BNode<T> * findMin(BNode<T> *t) const;
		//internal method to find the minimum value in a subtree
	BNode<T> * findMax(BNode<T> *t) const;
		//internal method to find the maximum value in a subtree
	bool contains (T& x, BNode<T> *t);
		//internal method to find if an item is in a subtre
	void makeEmpty(BNode<T> * & t);
		//internal method to delete all items in a subtree
	BNode<T> * clone(BNode<T> *t) const;
		//interal method to copy a subtree
	void printInorder(BNode<T> *t) const;
		//internal method to print a subtree using Inorder Traversal
	void printPostorder(BNode<T> *t) const;
		//internal method to print a subtree using Postorder Traversal
	void printPreorder(BNode<T> *t) const;
		//internal method to print a subtree using Preorder Traversal
	int height(BNode<T> *t) const;
		//internal method to return the height of subtree
};

//private member functions
template <class T>
int BinarySearchTree<T>::height(BNode<T> *t) const
{
	if(t==NULL)
		return -1;
	else
		return 1+std::max(height(t->left),height(t->right));
}

template <class T>
void BinarySearchTree<T>::printPreorder(BNode<T> *t) const
{
	if (t==NULL)
		return;
	if (t->duplicates > 0)
		std::cout<<t->element<< " Duplicates: " << t->duplicates<<std::endl;
	else
		std::cout<<t->element<<std::endl;
	//go left
	printInorder(t->left);
	//go right
	printInorder(t->right);
}

template <class T>
void BinarySearchTree<T>::printPostorder(BNode<T> *t) const
{
	if (t==NULL)
		return;
	//go left
	printInorder(t->left);
	//go right
	printInorder(t->right);
	std::cout<<t->element<<std::endl;
}

template <class T>
void BinarySearchTree<T>::printInorder(BNode<T> *t) const
{
	if (t==NULL)
		return;
	//go left
	printInorder(t->left);
	std::cout<<t->element<<std::endl;
	//go right
	printInorder(t->right);
}

template <class T>
BNode<T> * BinarySearchTree<T>::clone(BNode<T> *t) const
{
	if(t==NULL)
		return NULL;

	return new BNode<T>(t->element, clone(t->left), clone(t->right));
}

template <class T>
void BinarySearchTree<T>::makeEmpty(BNode<T> * & t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t=NULL;
}

template <class T>
bool BinarySearchTree<T>::contains (T& x, BNode<T> *t)
{
	if (t==NULL)
		return false;
	else if(x < t->element)
		return contains(x, t->left);
	else if(t->element < x)
		return contains(x, t->right);
	else
		return true;
}

template <class T>
BNode<T> * BinarySearchTree<T>::findMin(BNode<T> *t) const
{
	if(t==NULL)
		return NULL;
	if(t->left==NULL)
		return t;
	return findMin(t->left);
}

template <class T>
BNode<T> * BinarySearchTree<T>::findMax(BNode<T> *t) const
{
	if(t==NULL)
		return NULL;
	if(t->right==NULL);
	return t;
	return findMax(t->right);
}

template <class T>
void BinarySearchTree<T>::remove( T& x, BNode<T> * & t)
{
	if(t==NULL)
		return; //Item not found; do nothing
	if(x < t->element)
		remove(x,t->left); //x < t so go left
	else if(t->element < x)
		remove(x,t->right); //x > t so go right
	else if(t->duplicates > 0) //there are duplicates of the item so just mark it down
		t->duplicates--;
	else if(t->left !=NULL && t->right !=NULL) //x is at node and two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else //one child
	{
		BNode<T> *oldNode=t;
		t=(t->left !=NULL) ? t->left : t->right;
		delete oldNode;
	}
}

template <class T>
void BinarySearchTree<T>::insert( T& x, BNode<T> * & t) 
{
	if(t==NULL)
		t = new BNode<T>(x, NULL, NULL);
	else if(x < t->element)
		insert (x, t->left);
	else if(t->element < x)
		insert(x, t->right);
	else if (x==t->element)
	{
		std::cout<<t->element<<" is a duplicate" << std::endl;
		t->duplicates++; //duplicate so mark it
	}
}

//public members
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root=NULL;
	nodeCount=0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& otherBST)
{
	root = clone(otherBST.root);
	nodeCount=otherBST.nodeCount;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteAll();
}

template <class T>
void BinarySearchTree<T>::deleteAll()
{
	makeEmpty(root);
}

template <class T>
const T& BinarySearchTree<T>::findMin() const
{
	return findMin(root)->element;
}

template <class T>
const T& BinarySearchTree<T>::findMax() const
{
	return findMax(root)->element;
}

template <class T>
bool BinarySearchTree<T>::find(T& x)
{
	return contains(x, root);
}

template <class T>
bool BinarySearchTree<T>::isEmpty() const
{
	return (root==NULL);
}

template <class T>
void BinarySearchTree<T>::printInorderTraversal() const
{
	if (isEmpty()) //say if tree is empty
	{
		std::cout << "Tree is empty..." << std::endl;
		return;
	}
	printInorder(root);
}

template <class T>
void BinarySearchTree<T>::printPostorderTraversal() const
{
	if (isEmpty()) //say if tree is empty
	{
		std::cout << "Tree is empty..." << std::endl;
		return;
	}
	printPostorder(root);
}

template <class T>
void BinarySearchTree<T>::printPreorderTraversal() const
{
	if (isEmpty()) //say if tree is empty
	{
		std::cout << "Tree is empty..." << std::endl;
		return;
	}
	printPreorder(root);
}

template <class T>
void BinarySearchTree<T>::insert(T& x)
{
	insert(x,root);
}

template <class T>
int BinarySearchTree<T>::height() const
{
	return height(root);
}

template <class T>
void BinarySearchTree<T>::deleteNode(T& x)
{
	remove(x,root);
}

template <class T>
const BinarySearchTree<T> & BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rhs)
{
	if (this != &rhs)
	{
		deleteAll();
		root = clone(rhs.root);
	}
	return *this;
}

#endif