//BNode.h
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#ifndef BNODE_H
#define BNODE_H

template <class Type>
struct BNode
{
	Type element;
	BNode *left;
	BNode *right;
	int duplicates;

	//BNode();
	BNode( const Type& theElement, BNode *lt, BNode* rt)
		:element(theElement), left(lt), right(rt){}
	//~BNode();
};



#endif