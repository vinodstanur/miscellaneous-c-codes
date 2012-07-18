#include<stdio.h>
#include<stdlib.h>

struct NODE {
	int int_data;
	int bfactor;
	struct NODE *left;
	struct NODE *right;
};

struct NODE *add_to_AVL_tree (int, struct NODE *);
void print_tree (struct NODE *, int);
struct NODE *left_left_case(struct NODE *parent);
struct NODE *left_right_case(struct NODE *parent);
struct NODE *right_right_case(struct NODE *parent);
struct NODE *right_left_case(struct NODE *parent);

/*---------------MAIN FUNCTION--------------------*/
int main (void)
{
  int int_data;
  char choice;
  struct NODE *Tree = (struct NODE *) malloc (sizeof (struct NODE));
  Tree = NULL;
  printf ("\n type data (int): ");
  while (scanf("%d",&int_data) != EOF) {
      Tree = add_to_AVL_tree (int_data, Tree);
      printf("\n:--------TREE-------:\n");
      print_tree (Tree, 1);
      printf("\n:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:\n");
      printf ("type data (int): ");
  }
  return 0;
}

/*--------------------SUBROUTINES-------------------------*/

struct NODE *left_left_case(struct NODE *parent) 
{
	static struct NODE *temp1, *temp2;
	temp1 = parent->left;
       	parent->left = temp1->right;
	temp1->right = parent;
	parent->bfactor = 0;
	return temp1;
}


struct NODE *left_right_case(struct NODE *parent) 
{
	static struct NODE *temp1, *temp2;
	temp1 = parent->left;
	temp2 = temp1->right;
	temp1->right = temp2->left;
	temp2->left = temp1;
	parent->left = temp2->right;
	temp2->right = parent;
	return temp2;
}


struct NODE *right_right_case(struct NODE *parent) 
{
	static struct NODE *temp1, *temp2;
	temp1 = parent->right;
	parent->right = temp1->left;
	temp1->left = parent;
	parent->bfactor = 0;
	return temp1;
}


struct NODE *right_left_case(struct NODE *parent) 
{
	static struct NODE *temp1, *temp2;
	temp1 = parent->right;
	temp2 = temp1->left;
	temp1->left = temp2->right;
	temp2->right = temp1;
	parent->right = temp2->left;
	temp2->left = parent;
	return temp2;
}
struct NODE *add_to_AVL_tree (int int_data, struct NODE *parent)
{
  static int flag;
  if (parent == 0) {
      parent = (struct NODE *) malloc (sizeof (struct NODE));
      parent->int_data = int_data;
      parent->left = NULL;
      parent->right = NULL;
      parent->bfactor = 0;
      flag = 1;
      return parent;
  }
  if (int_data < parent->int_data) {
      parent->left = add_to_AVL_tree (int_data, parent->left);
      if (flag) {
	  switch (parent->bfactor -= 1) {
	    case 0:	
	      flag = 0;
	      break;
	    case -1:
	      break;
	    case -2:	
	      if (parent->left->bfactor == -1) {
		      parent = left_left_case(parent);
	      }
	      else {
		  parent = left_right_case(parent);
	      }
	      parent->bfactor = 0;
	      flag = 0;
	  }
      }
  }
  if (int_data > parent->int_data) {
      parent->right = add_to_AVL_tree (int_data, parent->right);
      if (flag) {
	  switch (parent->bfactor += 1)  {
	    case 0:		
	      flag = 0;
	      break;
	    case 1:
	      break;
 	    case 2:		
	      if (parent->right->bfactor == 1) {
			parent = right_right_case(parent);
	      }
	      else {
			parent = right_left_case(parent);
	      }
	      parent->bfactor = 0;
	      flag = 0;
	  }
      }
  }
  return (parent);
}

/* print_tree function (graphical tree printing - vertical) */
void print_tree (struct NODE *Tree, int Level)
{
  int i;
  if (Tree) {
      print_tree (Tree->right, Level + 1);
      printf ("\n");
      for (i = 0; i < Level; i++)
	printf ("  ");
      printf ("%d", Tree->int_data);
      print_tree (Tree->left, Level + 1);
  }
}

/*---------------------------------END--------------------------------*/
