#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

struct NODE
{
	int marked;
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
			tnode->marked = 0;
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

int traverse(NODE* node)
{
	if(node == NULL)
		return 0;

	
	int value = std::max(traverse(node->left), traverse(node->right));
	printf("Old value: %d\n", node->value);
	if(node->marked == 0)
	{
		node->value += value;
		node->marked = 1;
	}
	printf("New value: %d\n\n", node->value);
	return node->value;
}

int main()
{
	NODE *root = buildTree();
	int max = traverse(root);
	printf("Max: %d\n", max);
	delTree(root);
	root = NULL;
	return 0;
}