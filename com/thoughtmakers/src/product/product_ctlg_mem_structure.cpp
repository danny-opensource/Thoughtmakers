//***************************************************************************/
//File Name		: prodcut_ctlg_mem_structure.cpp
//Author		: krao24@gmail.com
//Description   : Main file for creating product tree structure
//**************************************************************************/
#include<iostream>
#include"../include/product_method_prototypes.h"
//#include"product_method_prototypes.h"
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
Product* createProduct(Product *product, string productName)
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
			Shop productShop;
			productShop.m_fCost = 3*i + 10; //temp cost for now
			productShop.m_ShopName = *shopIterator;
			productShop.m_nRank = 10;
			product->m_vProductShops.push_back(productShop);
		}


	}

	else if( productName < product->m_ProductName )
	{
		product->left = createProduct(product->left,productName);
	}

	else
	{
		product->right = createProduct(product->right,productName);
	}

	return product;

}

//*******************************************************************************/
//Description : Method to extract the shop from names from SHOP_INFO.txt
//Method Name : GetShopNames
//Parameters  : None
//returns None 
//*******************************************************************************/
void GetShopNames( )
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
void GetProductNames()
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

//******************************************************************/
//
//Method Name : debugDisplay
//Parameters  : root[in] -> Root node of the tree
//Returns     : Nothing
//
//*****************************************************************/

void debugDisplay(Product* root)
{
	if( root != NULL )
	{
		cout<<root->m_ProductName<<endl;
		debugDisplay(root->left);
		debugDisplay(root->right);
	}
}

//******************************************************************/
//
//Method Name : debugDisplaypreorder
//Parameters  : root[in] -> Root node of the tree
//Returns     : Nothing
//
//*****************************************************************/
void debugDisplayPreorder(Product* root)
{
	if(root != NULL)
	{
		debugDisplayPreorder(root->left);
		cout<<root->m_ProductName<<endl;
		debugDisplayPreorder(root->right);
	}
		
}

//******************************************************************/
//
//Method Name : GetShopesInLocation
//Parameters  : 
//vShopsFromLocation -> List of shops from a particular location
//vAllShops	     -> List of shops that has the product available
//Returns     : List of shops in particular location where the 
//		product is available
//
//*****************************************************************/
vector<string> GetShopesInLocation(vector<string> vShopsFromLocation, vector<string> vAllShops)
{
	vector<string> vShopsInLocation;
	vector<string>::iterator iteratorLocation, iteratorShops;
	iteratorLocation = vShopsFromLocation.begin();
	iteratorShops = vAllShops.begin();
	int locationLength = vShopsFromLocation.size();
	int shopsLength = vAllShops.size();

	if( locationLength > shopsLength )
	 {
		for(;iteratorLocation != vShopsFromLocation.end();)
		{
			if( *iteratorLocation == *iteratorShops )
			{
				string sLocation = *iteratorLocation;
				vShopsInLocation.push_back(sLocation);
				iteratorLocation++;iteratorShops++;
			}
			else
				iteratorLocation++;
			
			if( iteratorLocation == vShopsFromLocation.end() && 
				iteratorShops != vAllShops.end() )
				iteratorLocation = vShopsFromLocation.begin();
			
			if( iteratorShops == vAllShops.end() ) break;
		}
	
	 }

	else
	{
		
		for(;iteratorShops != vAllShops.end();)
	 	{
			if( *iteratorLocation == *iteratorShops )
			{
				string sLocation = *iteratorShops;
				vShopsInLocation.push_back(sLocation);
				iteratorLocation++;iteratorShops++;
			}
			else
				iteratorShops++;
			
			if( iteratorShops == vAllShops.end() && 
				iteratorLocation != vShopsFromLocation.end() )
				iteratorShops = vAllShops.begin();
			
			if( iteratorLocation == vShopsFromLocation.end() ) break;
	

		}

	}
	
	return vShopsInLocation;
	
}
int main()
{
	/*TODO : Move this file operations to utility method*/
	//Product _temp;
	GetProductNames();
	GetShopNames();

	Product *proHead = NULL;
	vector<string>::iterator prodIterator = csProductName.begin();
	for(prodIterator = csProductName.begin() ; prodIterator != csProductName.end(); prodIterator++)
	{
		proHead = createProduct(proHead,*prodIterator);
	}

	debugDisplay( proHead );
	cout<<"Pre-order"<<endl;
	debugDisplayPreorder(proHead);
	return 0;
}

