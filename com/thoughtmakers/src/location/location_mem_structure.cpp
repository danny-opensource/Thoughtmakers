#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "../include/Location.h"
#include "../include/location_mtd_proto.h"
#include "../include/LocationNode.h"
using namespace std;
vector<string> locations;
location_node *root;
int main()
{
	readLocationFiles();
	buildBST();
	debugPrintTree(root);
	return 0;
}

void readLocationFiles()
{
	string line;
	int line_index = 0;
	ifstream locFile;
	locFile.open("../../test/LOC_INFO.txt");
	if(locFile.is_open())
	{
		while(!locFile.eof())
		{
			getline(locFile,line);
			if(!line.empty())
				locations.push_back(line);
		}
		locFile.close();
	}
	else
	{
		cout<<"Unable to open file"<<endl;
	}
}

void buildBST()
{
	int index=0;
	for(int i=0;i<locations.size();i++)
	{
		insertIntoTree(locations[i]);
	} 
}

void insertIntoTree(string loc)
{
	if(root == NULL)
	{
		root = new location_node;
		root->left = NULL;
		root->right = NULL;
		root->loc_data = loc;
		return;
	}
	insert(root,loc);
}

void insert(location_node *current, string loc)
{
	if(loc < current->loc_data)
	{
		if(current->left != NULL)
		{
			insert(current->left,loc);
		}
		else
		{
			current->left = new location_node;
			current->left->left = NULL;
			current->left->right = NULL;
			current->left->loc_data = loc;
		}
	}
	else
	{
		if(current->right != NULL)
		{
			insert(current->right,loc);
		}
		else
		{
			current->right = new location_node;
			current->right->left = NULL;
			current->right->right = NULL;
			current->right->loc_data = loc;
		}
	}
}

void debugPrintTree(location_node *current)
{
	if(current->left != NULL)
	{
		debugPrintTree(current->left);
	}
	cout<<current->loc_data<<"\t";
	if(current->right != NULL)
	{
		debugPrintTree(current->right);
	}
}
