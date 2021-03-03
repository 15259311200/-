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
		cout<<"�����ڴ�ʧ��"<<endl;
		exit(1); 
	} 
	tree->data=InOrder[k];
	tree->left=CreateTree(tree->left,PostOrder,InOrder,k);//������
	tree->right=CreateTree(tree->right,PostOrder+k,InOrder+k+1,length-k-1);//������ 
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
	int length;//�������Ľ��Ϊ���ٸ� 
	cin>>length; 
	cin>>PostOrder;//���� 
	cin>>InOrder;//����
	cout<<"��������ǣ�"; 
	tree=CreateTree(tree,PostOrder,InOrder,length);
	PreOrder(tree);
} 
/*ʵ������
  ���� 4132657
  ���� 2315764
  ���� 1234567 
  7
  2315764
  1234567
*/
