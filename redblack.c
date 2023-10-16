#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
    char color;
    struct node* parent;
};

struct node* root = NULL;

void new_node(struct node* decide, int key){
    decide = malloc(sizeof(struct node));
    decide->left = NULL;
    decide->right = NULL;
    decide->data = key;
    decide->color = 'r';
    decide->parent = NULL;
}

void right_rotation(struct node* temp){
    struct node* l = temp->left;
	temp->left = l->right;
	if (temp->left)
		temp->left->parent = temp;
	l->parent = temp->parent;
	if (!temp->parent) root = l;
	else if (temp == temp->parent->left) temp->parent->left = l;
	else temp->parent->right = l;

	l->right = temp;
	temp->parent = l;
}

void left_rotation(struct node *temp){
    struct node* r = temp->right;
	temp->right = r->left;
	if (temp->right)
		temp->right->parent = temp;
	r->parent = temp->parent;
	if (!temp->parent)
		root = r;
	else if (temp == temp->parent->left)
		temp->parent->left = r;
	else
		temp->parent->right = r;
	r->left = temp;
	temp->parent = r;
}

void fixup(struct node* root, struct node* pt)
{
	struct node* parent_pt = NULL;
	struct node* grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != 'b')
		&& (pt->parent->color == 'r')) 
	{
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		/* Case : A
			Parent of pt is left child 
			of Grand-parent of
		pt */
		if (parent_pt == grand_parent_pt->left) 
		{

			struct node* uncle_pt = grand_parent_pt->right;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == 'r') 
			{
				grand_parent_pt->color = 'r';
				parent_pt->color = 'b';
				uncle_pt->color = 'b';
				pt = grand_parent_pt;
			}

			else {

				/* Case : 2
					pt is right child of its parent
					Left-rotation required */
				if (pt == parent_pt->right) {
					leftrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
					pt is left child of its parent
					Right-rotation required */
				rightrotate(grand_parent_pt);
				char t = parent_pt->color;//see this line -----------------------------------------------------------------------------------
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = t;
				pt = parent_pt;
			}
		}

		/* Case : B
			Parent of pt is right 
			child of Grand-parent of
		pt */
		else {
			struct node* uncle_pt = grand_parent_pt->left;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == 'r')) 
			{
				grand_parent_pt->color = 'r';
				parent_pt->color = 'b';
				uncle_pt->color = 'b';
				pt = grand_parent_pt;
			}
			else {
				/* Case : 2
				pt is left child of its parent
				Right-rotation required */
				if (pt == parent_pt->left) {
					rightrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
					pt is right child of its parent
					Left-rotation required */
				leftrotate(grand_parent_pt);
				char t = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = t;
				pt = parent_pt;
			}
		}
	}
}

struct node* insertion(struct node* root, struct node* new){
    if(root == NULL) return new;

    if(new->data < root->data){
        root->left = insertion(root->left, new);
        root->left->parent = root;
    }else if(new->data > root->data){
        root->right = insertion(root->right, new);
        root->parent = root;
    }

    return root;
}

int main(){
    return 0;
}