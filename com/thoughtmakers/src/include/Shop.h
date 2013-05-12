//***************************************************************************/
//File Name		: Shop.h
//Author		: krao24@gmail.com
//Description   : Header file for Shops structure
//**************************************************************************/

#include<string>
#include "Location.h"
using namespace std;
struct Shop
{
	string m_ShopName;
	location shop_location;
	float cost;
	int m_nRank;
};

