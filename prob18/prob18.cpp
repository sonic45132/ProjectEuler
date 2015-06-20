#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

struct NODE
{
	int value;
	NODE *left;
	NODE *right;
};

void delTree(NODE *tree)
{
	if(tree != NULL)
	{
		delTree(tree->left);
		delTree(tree->right);
		delete tree;
	}
}

NODE* buildTree()
{
	FILE *ifp = fopen("list.txt", "r");
	int res = 0;
	int line = 2;
	int temp = 0;
	std::vector<NODE*> prev;
	std::vector<NODE*> curr;

	NODE *root = new NODE;
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

int traverse(NODE* root, unsigned int *fpath)
{
	int max = 0;
	int value = 0;
	unsigned int mpath = 0;
	unsigned int path = 0;

	NODE *node = root;

	for(;path < 0xFFFFFFF;path++)
	{
		node = root;
		value = 0;
		for(int i = 0; i < 14; i++)
		{
			value += node->value;
			//printf("node: %d\n", node->value);

			if((path&(0x1 << i)) == 0)
				node = node->left;
			else
				node = node->right;

		}
		value += node->value;
		if(value > max)
		{
			max = value;
			mpath = path;
		}
	}
	(*fpath) = mpath;
	return max;
}

void printPath(NODE* root, unsigned int path)
{
	NODE *node = root;

	for(int i = 0; i < 14; i++)
	{
		printf("node: %d\n", node->value);

		if((path&(0x1 << i)) == 0)
			node = node->left;
		else
			node = node->right;
	}
	printf("node: %d\n", node->value);
}

int main()
{
	NODE *root = buildTree();
	unsigned int path = 0;
	int max = traverse(root, &path);
	printf("Max: %d\n", max);
	printPath(root, path);
	delTree(root);
	root = NULL;
	return 0;
}