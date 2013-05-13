///////////////////////////////////////////////////////////
//
//
//	File Name : product_method_protoypes.h
//	Author    : krao24@gmail.com
//	Desc      : Header file for all the product method 
//
////////////////////////////////////////////////////////////

#include<vector>
#include<string>
#include"Product.h"

using namespace std;

Product* createProduct(Product* root, string productName);
void debugDisplay(Product* root);
void debugDisplayPreorder(Product* root);
vector<string> GetShopesInLocation(vector<string> vLocationShops, vector<string> vAllShops);
void GetShopNames();
void GetProdutNames();
					
