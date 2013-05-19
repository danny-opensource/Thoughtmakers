/*
 * ThoughtMakers, 2013
 */

/*
 * location_mem_structure.cpp
 * Author: madan1988 (Git user)
 * Builds a Binary Search Tree with all the locations stored in the LOC_INFO.
 * 
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "../include/Location.h"
#include "../include/location_mtd_proto.h"
#include "../include/LocationNode.h"
#include "../include/location_utils.h"
#include "../include/sys_load.h"
using namespace std;
vector<string> locations;
location_node *root;
/*
 *Main invocation for the tree build. 
 * Must be removed after product evolution. Entry point is from main class triggered from Linux boot
 */
int main()
{
	readLocationFiles(); // Read contents of location file
	buildBST(); // Build BST
	debugPrintTree(root); // debugging function to print the tree. Will be removed after test.
	return 0;
}

/*
 * File read for the location data from a location specified.
 */
void readLocationFiles()
{
	string line;
	int line_index = 0;
	ifstream locFile;
	locFile.open("../../test/LOC_INFO.txt");  // Must be stored in properties. Will be fixed in future releases
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

/*
 * Build the tree based on the location data extracted
 */
void buildBST()
{
	int index=0;
	for(int i=0;i<locations.size();i++)
	{
		insert(root,locations[i]);
	} 
}

location_node* createNode(string loc)
{
	location_node *current = new location_node;
	vector<string> shopList;
	location *currentLocation = new location;
	currentLocation->location_name = loc;
	currentLocation->shopList = shopList; // [TO-DO] Compute this and pass the vector of shop names
	current->left = NULL;
	current->right = NULL;
	current->loc_data = currentLocation;
	return current;

}

/*
 * tree nodes insertion
 */
void insert(location_node *current, string loc)
{
	if(current == NULL)
	{
		/* Case triggered only when root is null */
		current = createNode(loc);
		root = current;
	}
	else if(loc < (current->loc_data->location_name))
	{
		if(current->left != NULL)
		{
			insert(current->left,loc);
		}
		else
		{
			current->left = createNode(loc);
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
			current->right = createNode(loc);
		}
	}
}

/*
 * Debug method to print tree.
 * Note: All debug/test methods start with debugXXX();
*/
void debugPrintTree(location_node *current)
{
	if(current->left != NULL)
	{
		debugPrintTree(current->left);
	}
	cout<<current->loc_data->location_name<<"\t";
	if(current->right != NULL)
	{
		debugPrintTree(current->right);
	}
}
