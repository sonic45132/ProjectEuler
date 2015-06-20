#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <memory>

struct NODE
{
	int value;
	std::shared_ptr<NODE> left;
	std::shared_ptr<NODE> right;
};

void delTree(std::shared_ptr<NODE> node)
{
	if(tree != NULL)
	{
		delTree(tree->left);
		delTree(tree->right);
		delete tree;
	}
}

void buildTree(std::shared_ptr<NODE> root)
{
	FILE *ifp = fopen("list.txt", "r");
	int res = 0;
	int line = 2;
	int temp = 0;
	std::vector<NODE*> prev;
	std::vector<NODE*> curr;


	NODE *tnode;
	res = fscanf(ifp, "%d", &temp);
	root->value = temp;
	root->left = NULL;
	root->right = NULL;
	printf("%d\n", root->value);
	prev.push_back(root);

	while(res != EOF)
	{
		for(int i = 0; i < line; i++)
		{
			res = fscanf(ifp, "%02d", &temp);
			
			if(res == EOF)
				break;
			
			tnode = new NODE;
			tnode->value = temp;
			tnode->left = NULL;
			tnode->right = NULL;
			printf("%02d ", tnode->value);
			curr.push_back(tnode);

			if((i-1) >= 0)
				prev[i-1]->right = tnode;

			if(i < prev.size())
				prev[i]->left = tnode;
		}

		prev = curr;
		curr.clear();
		line++;
		printf("\n");
	}

	return root;
}

int main()
{
	std:shared_ptr<NODE> root = std::make_shared<NODE>();
	buildTree(root);
	printf("Root: %d\n", root->value);
	delTree(root);
	root = NULL;
	return 0;
}