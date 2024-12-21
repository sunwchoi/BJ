#include <iostream>

using namespace std;

int C;

struct node {
	char c;
	struct node* child[4];
};

struct node* tree;

int makeTree(const string& str, int pos, struct node* parent, int childNum)
{	
	if (pos == str.length())
		return pos;

	struct node* nde = (struct node*)malloc(sizeof(struct node));

	nde->c = str[pos];

	if (parent != NULL)
		parent->child[childNum] = nde;
	else
		tree = nde;

	int end_pos = pos + 1;
	if (str[pos] == 'x')
	{
		for (int i = 0; i < 4; i++)
			end_pos = makeTree(str, end_pos, nde, i); 
	}
	return end_pos;
}

void iterTree(struct node* nde)
{
	cout << nde->c;
	if (nde->c != 'x')
	{
		free(nde);
		return ;
	}

	iterTree(nde->child[2]);
	iterTree(nde->child[3]);
	iterTree(nde->child[0]);
	iterTree(nde->child[1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	string s;
	for (int i = 0; i < C; i++)
	{
		cin >> s;
		makeTree(s, 0, NULL, 0);
		iterTree(tree);
		cout << "\n";
	}
}
