#ifndef SYS_LOAD
#define SYS_LOAD
#include<vector>
#include<string>
#include<map>
using namespace std;

static map < string,vector<string> > location_shop_map;
/* Declare all the method prototypes that will be loaded when the system boots
 */
void loadLocationShopMap();  //Impl in utils/LocationUtils.cpp
vector<string> getShopsForLocation(string);
#endif
