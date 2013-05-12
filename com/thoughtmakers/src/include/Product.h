//***************************************************************************/
//File Name		: Produt.cpp
//Author		: krao24@gmail.com
//Description   : Header file for Product structure
//**************************************************************************/

#include<vector>
#include<vector>
#include<string>
#include "ProductShop.h"
using namespace std;
struct Product
{

	Product* createProduct(Product *product, string productName);
	void GetShopNames();
	void GetProductNames();
	string m_ProductName;
	vector<ProductShop> m_vProductShops;
	Product *left;
	Product *right;
};

