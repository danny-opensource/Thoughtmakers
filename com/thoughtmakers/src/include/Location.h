#ifndef LOCATION
#define LOCATION
#include<string>
#include<vector>
#include "Shop.h"
/*
 * Data Structure to store the location details. 
 * This structure can grow in the future depending on the rule-sets defined by the product
 */
struct location
{
std::string location_name;
std::vector<string> shopList;
};

#endif
