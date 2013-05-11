#include<iostream>
#include"ProductShop.h"
#include<string>
#include<vector>

using namespace std;

typedef struct Product
{
 	vector<ProductShop> ProductShops;
	string m_sProductName;
	Product *m_pLeft;
	Product *m_pRight;
};

