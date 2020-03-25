#include <iostream>
using namespace std;

double tree_max(TreeNode *tree)
{
	if(tree == NULL)
		return 0;
	double max = tree.get_value();
	double lmax = tree_max(tree.get_left());
	double rmax = tree_max(tree.get_right());
	if(lmax>max)
		max = lmax;
	if(rmax>max)
		max = rmax;
	return max;
}