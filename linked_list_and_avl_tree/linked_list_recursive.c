#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list {
	struct list *next;
	int num;
};

struct list *revp; 
/*-------------------ADD LIST-----------------------------------*/

struct list *addlist(struct list *p, int digit)
{
	if(p == NULL) {
		p = (struct list *) malloc(sizeof(struct list));
		p->num = digit;
		p->next = NULL;
	} else
		p->next = addlist(p->next, digit);
	return p;
}
		
/*-----------------PRINT LIST----------------------------------*/

void printlist(struct list *p)
{
	printf("%d\t\t\t\t----> %x\n",p->num,p->next);
	if(p->next != NULL)
		printlist(p->next);

}

/*---------------------REVERSE LIST-------------------------------*/

struct list *reverse_it(struct list *p, struct list *memory)
{	
	static struct list *return_pointer;
	if(p->next != NULL) {
		reverse_it(p->next, p);
	} else 
		return_pointer = p;
	p->next = memory;
	return return_pointer;
}
	
struct list *reverse(struct list *p)
{
	return reverse_it(p, NULL);
}

/*------------------------MAIN FUNCTION---------------------------*/

void main(void)
{
	struct list *root;
	root = NULL;
	struct list *q = root;
	int digit;
	printf("ENTER NUMBERS TO BE STORED IN LINKED LIST FOLLOWED\n");
	printf("PRESS Ctrl + D to terminate\n");
	while(scanf("%d", &digit) != EOF) 
		root = addlist(root, digit);
	printf("linked list (data and next link)\n");
	printlist(root);         //PRINT LIST DATA
	root = reverse(root);    //REVERSE THE LIST
	printf("reversed linked list (data and next link)\n");
	printlist(root);         //PRINT REVERSED LIST DATA
}
