// BST.cpp : main project file.
//Author: Jayant Gandhi
//Created on: 10/26/2012
//Last Edited on: 10/26/2012

#include <iostream>
#include "BinarySearchTree.h"
#include "INT.h"
#include "CHAR.h"
#include <fstream>
#include <vector>

using namespace std;

bool inputFileINT(const char* fileName, vector<int>& intVector);
void populateTree(vector<int>& intVector, BinarySearchTree<INT>& aTree);
bool inputFileCHAR(const char* fileName, BinarySearchTree<CHAR>& aTree);

int main(int argc, const char *argv[])
{
	bool inputOK;

	BinarySearchTree<INT> intTree;
	BinarySearchTree<CHAR> charTree;
	vector<int> inputInt;

	if(argc >=2)
		inputOK=true;
	else
	{
		inputOK=false;
		cout<<"No command line argument input files"<<endl;
		cout<<"Please run program again passing a INT input file and a CHAR input file as command line arguments (in that order)."<<endl;
		return 1;
	}

	if (inputFileINT(argv[1], inputInt)) //input INT file
	{
		populateTree(inputInt, intTree);
		intTree.printInorderTraversal();
		intTree.printPostorderTraversal();
		intTree.printPreorderTraversal();
		cout<< "Height of Tree: " << intTree.height() <<endl;
		cout<< "Looking for 85168..." <<endl;
		INT item(85168);
		if (intTree.find(item))
			cout<<"Found it!"<<endl;
		else
			cout<<"Not there..."<<endl;
		cout<<"Now deleting 85168..."<<endl;
		
		intTree.deleteNode(item);
		cout<< "Looking for 85168..." <<endl;
		if (intTree.find(item))
			cout<<"Found it!"<<endl;
		else
			cout<<"Not there..."<<endl;
	}
	else
	{
		cout<<"Problem with input file."<<endl;
		return 2;
	}

	if (argc >=3)
		inputOK=true;
	else
	{
		inputOK=false;
		cout<<"No command line argument input file for CHAR type"<<endl;
		cout<<"Please run program again passing a CHAR input file second."<<endl;
		return 3;
	}

	if (inputFileCHAR(argv[2], charTree))
	{
		charTree.printInorderTraversal();
		charTree.printPostorderTraversal();
		charTree.printPreorderTraversal();
		cout<< "Height of Tree: " << charTree.height() <<endl;
		cout<< "Looking for 'fee'..." <<endl;
		CHAR item("fee");
		if (charTree.find(item))
			cout<<"Found it!"<<endl;
		else
			cout<<"Not there..."<<endl;
		cout<<"Now deleting 'fee'..."<<endl;
		
		charTree.deleteNode(item);
		cout<< "Looking for 'fee'..." <<endl;
		if (charTree.find(item))
			cout<<"Found it!"<<endl;
		else
			cout<<"Not there..."<<endl;
	}
	else
	{
		cout<<"Problem with input file."<<endl;
		return 4;
	}

    return 0;
}

bool inputFileINT(const char* fileName, vector<int>& intVector)
{
	int theInput;

	cout <<"Opening INT input file..."<<endl;
	ifstream INTData;
	INTData.open(fileName);

	if (!INTData)
	{
		INTData.close();
		cout << "Sorry, I cannot seem to find this file. \nPlease restart the program.";
		return false;
	}

	while(INTData)
	{
		INTData >> theInput;
		intVector.push_back(theInput);
	}
	INTData.close();
	cout<< "Done Inputing File!" << endl << endl;

	return true;
}

void populateTree(vector<int>& intVector, BinarySearchTree<INT>& aTree)
{
	int size=intVector.size();
	for(int i=0; i<size; i++)
	{
		INT temp=intVector[i];
		aTree.insert(temp);
	}
}

bool inputFileCHAR(const char* fileName, BinarySearchTree<CHAR>& aTree)
{
	char input [256];

	cout <<"Opening CHAR input file..."<<endl; 
	ifstream CHARData;
	CHARData.open(fileName);

	if (!CHARData)
	{
		CHARData.close();
		cout << "Sorry, I cannot seem to find this file. \nPlease restart the program.";
		return false;
	}

	while(CHARData.getline (input, 100))
	{
		CHAR temp (input);
		//cout << temp << endl;
		aTree.insert(temp);
	}
	CHARData.close();
	cout<< "Done Inputing File!" << endl << endl;

	return true;
}