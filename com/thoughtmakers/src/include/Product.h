//***************************************************************************/
//File Name		: Produt.cpp
//Author		: krao24@gmail.com
//Description   : Header file for Product structure
//**************************************************************************/
#ifndef PRODUCT
#define PRODUCT
#include<vector>
#include<string>
#include "Shop.h"
using namespace std;


struct Product
{
	Product* createProduct(Product *product, string productName);
	void GetShopNames();
	void GetProductNames();
	string m_ProductName;
	vector<Shop> m_vProductShops;
	Product *left;
	Product *right;
};
#endif
