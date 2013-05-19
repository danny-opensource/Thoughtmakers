/*
 * Define all the method prototypes used by location_mem_structure.cpp
 */
#ifndef LOCATION_METHOD_PROTOTYPES
#define LOCATION_METHOD_PROTOTYPES
#include "LocationNode.h"
void readLocationFiles();
void buildBST();
location_node* createNode(string);
void insert(location_node*,std::string);
void debugPrintTree(location_node*);
#endif
