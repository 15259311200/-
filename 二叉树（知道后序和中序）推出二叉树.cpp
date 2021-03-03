#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef struct BinaryTree
{
	struct BinaryTree *left,*right;
	char data;
}BinTreeNode;
BinTreeNode *CreateTree(BinTreeNode *tree,char *PostOrder,char *InOrder,int length)
{
	int k=0;
	if(length==0) return NULL; 
	while(PostOrder[length-1]!=InOrder[k]) k++;
	if((tree=(BinTreeNode *)malloc(sizeof(BinTreeNode)))==NULL)
	{
		cout<<"分配内存失败"<<endl;
		exit(1); 
	} 
	tree->data=InOrder[k];
	tree->left=CreateTree(tree->left,PostOrder,InOrder,k);//左子树
	tree->right=CreateTree(tree->right,PostOrder+k,InOrder+k+1,length-k-1);//右子树 
	return tree;
} 
void PreOrder(BinTreeNode *tree)
{
	if(tree)
	{
		cout<<tree->data;
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}
int main()
{
	BinTreeNode *tree=NULL;
	char PostOrder[50];
	char InOrder[50];
	int length;//二叉树的结点为多少个 
	cin>>length; 
	cin>>PostOrder;//后序 
	cin>>InOrder;//中序
	cout<<"先序遍历是："; 
	tree=CreateTree(tree,PostOrder,InOrder,length);
	PreOrder(tree);
} 
/*实验数据
  先序 4132657
  后序 2315764
  中序 1234567 
  7
  2315764
  1234567
*/
