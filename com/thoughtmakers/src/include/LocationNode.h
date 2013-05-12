#ifndef LOCATION_NODE
#define LOCATION_NODE
#include "Location.h"

/*
 * Data Structure holding representing each node of the Location tree. 
 * No changes to be done to this structure. Any rule-set based changes must be done in Location.h 
*/

struct location_node
{
location *loc_data;
location_node *left;
location_node *right;
};

#endif
