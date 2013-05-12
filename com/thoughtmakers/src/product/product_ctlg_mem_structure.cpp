//***************************************************************************/
//File Name		: prodcut_ctlg_mem_structure.cpp
//Author		: krao24@gmail.com
//Description   : Main file for creating product tree structure
//**************************************************************************/
#include<iostream>
#include "../include/Product.h"
#include<string>
#include<vector>
#include<fstream>
using namespace std;


vector<string> csProductName;
vector<string> csShopName;


//*************************************************************************************/
//Description : Main method to create the BST
//Method Name : createProduct
//Parameters  : 2
///product[in]		-> The product node to be inserted
///productName[in]  -> The name of the product. It becomes the name of the node itself
//
//returns product node 
//*************************************************************************************/
Product* Product::createProduct(Product *product, string productName)
{
	vector<string>::iterator shopIterator = csShopName.begin();
	Product *temp = product;
	if( product == NULL )
	{

		product = new Product();
		product->left = NULL;
		product->right = NULL;
		product->m_ProductName = productName;
		int i = 1;
		for(shopIterator = csShopName.begin(); shopIterator != csShopName.end(); shopIterator++)
		{
			i++;
			ProductShop productShop;
			productShop.m_fCost = 3*i + 10;
			productShop.m_sShops.m_ShopName = *shopIterator;
			productShop.m_sShops.m_nRank = 10;
			product->m_vProductShops.push_back(productShop);
		}


	}

	else if( productName < product->m_ProductName )
	{
		product->left = product->createProduct(product->left,productName);
	}

	else
	{
		product->right = product->createProduct(product->right,productName);
	}

	return product;

}

//*******************************************************************************/
//Description : Method to extract the shop from names from SHOP_INFO.txt
//Method Name : GetShopNames
//Parameters  : None
//returns None 
//*******************************************************************************/
void Product::GetShopNames( )
{
	string line;
	fstream shopInfo ( "../../test/SHOPS_INFO.txt" );
	if( shopInfo.is_open() )
	{
		while( shopInfo.good() )
		{
			getline(shopInfo,line);
			if(!line.empty())
				csShopName.push_back(line);
		}
	}
	else
	{
		cout<<"Unable to open file CP1"<<endl;
	}
}

//********************************************************************************/
//Description : Method to extract the product names from PRODUCT_INFO.txt
//Method Name : GetProductNames
//Parameters  : None
//returns None 
//********************************************************************************/
void Product::GetProductNames()
{
	string line;
	fstream productInfo ( "../../test/PRODUCT_INFO.txt" );

	if( productInfo.is_open() )
	{
		while( productInfo.good() )
		{
			getline(productInfo,line);
			if(!line.empty())
				csProductName.push_back(line);
		}
	}
	else
	{
		cout<<"Unable to open file"<<endl;
	}
}
int main()
{
	/*TODO : Move this file operations to utility method*/
	Product _temp;
	_temp.GetProductNames();
	_temp.GetShopNames();

	Product *proHead = NULL;
	vector<string>::iterator prodIterator = csProductName.begin();
	for(prodIterator = csProductName.begin() ; prodIterator != csProductName.end(); prodIterator++)
	{
		proHead =proHead->createProduct(proHead,*prodIterator);
	}
	return 0;
}

