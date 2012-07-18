#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
struct tnode {     /* the tree node: */
       int num;           /* points to the text */
       int count;            /* number of occurrences */
       struct tnode *left;   /* left child */
       struct tnode *right;  /* right child */
};

#define BUFSIZE 1000
#define MAXWORD 100

struct tnode *addtree(struct tnode *, int);
void inorder_print(struct tnode *);
void preorder_print(struct tnode *);
void postorder_print(struct tnode *);
struct tnode *talloc(void);
char buf[BUFSIZE];
int bufp;
int height(struct tnode *);

   /* word frequency count */
int main(void)
{
       struct tnode *root;
       int digit;
       root = NULL;
       while (scanf("%d", &digit) != EOF)
     	        	root = addtree(root, digit);
       printf("inorder:\n");
       inorder_print(root);
       printf("preorder:\n");
       preorder_print(root);
       printf("postorder:\n");
       postorder_print(root);
       printf("%x",root);
       printf("height of tree = %d", height(root));
	return 0;
}


   /* addtree:  add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, int digit)
{	
       if (p == NULL) {     /* a new word has arrived */
           p = talloc();    /* make a new node */
           p->num = digit;
           p->count = 1;
           p->left = p->right = NULL;
       } else if (p->num == digit)
           p->count++;      /* repeated word */
       else if (p->num > digit)   /* less than into left subtree */
           p->left = addtree(p->left, digit);
       else                 /* greater than into right subtree */
           p->right = addtree(p->right, digit);
       return p;
}

struct tnode *talloc(void)
{
       return (struct tnode *) malloc(sizeof(struct tnode));
}

void inorder_print(struct tnode *p)
{
	if(p != NULL) {
		inorder_print(p->left);
		printf("%d\n",p->num);
		inorder_print(p->right);
	}
}

void preorder_print(struct tnode *p)
{
	if(p != 0) {
		printf("%d\n",p->num);
		preorder_print(p->left);
		preorder_print(p->right);
	}
}

void postorder_print(struct tnode *p)
{
	if(p != 0) {
		postorder_print(p->left);
		postorder_print(p->right);
		printf("%d\n",p->num);
	}
}


int height(struct tnode *p) 
{

	if (p == NULL)
		return 0;
	int left, right;
	left = right = 0;
	printf("l-%d\n",left = height(p->left));
	printf("r-%d\n",right = height(p->right));
	
	if(left < right)
		return right +1;
	else 
		return left + 1;
}



