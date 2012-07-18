#include<stdio.h>
#include<stdlib.h>
struct node {
	int coef;
	int exp;
	struct node *next;
};

/*----------add new node------------------------------------*/
struct node *new_node(int coef, int exp)
{
	struct node *m = malloc(sizeof(struct node));
	m->coef = coef;
	m->exp = exp;
	m->next = 0;
}

/*-------------addlist--------------------------------------*/
 struct node *addlist(struct node *p, int coef, int exp)
{
	struct node *temp = p;
	if(p == 0)
		return new_node(coef, exp);
	else 
		for(;temp->next != NULL;)
			temp = temp->next;
	temp->next = new_node(coef, exp);
	return p;

}

/*--------------print list---------------------------------*/
print_result_poly(struct node *p)
{
	if(p != 0) {
		printf("%dx^%d ", p->coef, p->exp);
		print_result_poly(p->next);
	}
}		
	

/*-----------add polynomial--------------------------------*/

struct node *add_polynomial(struct node *point1, struct node *point2, struct node *result)
{
	int coef1,coef2,exp1,exp2;
	while(point1 || point2) {
		if(point1 != NULL) {
			coef1 = point1->coef;
			exp1 = point1->exp;
		} else 
		       exp1 = -1;	
		if(point2 != NULL ) {
			coef2 = point2->coef;
			exp2 = point2->exp;
		} else 
			exp2 = -1;
		if(exp1 == exp2) {
			result = addlist(result, (coef1 + coef2), exp1);
			point1 = point1->next;
			point2 = point2->next;
		} else if(exp1 > exp2) {
			result = addlist(result, coef1, exp1);
			point1 = point1->next;
		} else {
			result = addlist(result, coef2, exp2);
			point2 = point2->next;
		}

	}
	return result;

}
/*----------------main function---------------------------*/
void main()
{	
	
	struct node *root[] = {NULL, NULL};
	struct node *point1, *point2;
	int i;
	int coef, exp;
	for(i = 0; i < 2; i ++) {
		printf("ENTER POLYNOMIAL no:%d (COEFFICIENT AND EXPONENT):\n",i);
		while(scanf("%d%d", &coef, &exp) != EOF)
			root[i] = addlist(root[i], coef, exp);
	}
	struct node *result = NULL;
	result = add_polynomial(root[0], root[1], result);
	print_result_poly(result);	
}

