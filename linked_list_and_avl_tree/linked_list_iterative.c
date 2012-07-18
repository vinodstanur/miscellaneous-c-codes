#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list {
	struct list *next;
	int num;
};


/*-------------------ADD LIST-----------------------------------*/

struct list *addlist(struct list *p, int digit)
{
	static struct list *first_node;
	static struct list *previous;
	if (p == NULL) {
		p = (struct list *) malloc(sizeof(struct list));
			first_node = p;
		previous = p;
		p->num = digit;
		p->next = NULL;
	} else {
		previous->next = (struct list *)malloc(sizeof(struct list));
		previous = previous->next;
		previous->num = digit;
		previous->next = NULL;
	}
	return first_node;	//RETURN THE STARTING NODE ALWAYS	
	 
}
		
/*-----------------PRINT LIST----------------------------------*/

void printlist(struct list *p)
{
	printf("%d\t\t\t\t----> %x\n",p->num,p->next);
	if(p->next != NULL)
		printlist(p->next);

}

/*---------------------REVERSE LIST-------------------------------*/

struct list *reverse(struct list *p)
{	
	struct list *new_root;
	struct list *list_buffer[1000];
	int i;
	for(i = 0; p != NULL; i++) {
		list_buffer[i] = p;
		p = p->next;
	}
	i -= 1;
	new_root = list_buffer[i];
	for(; i > 0; i--)
		(list_buffer[i])->next = list_buffer[i - 1];
	(list_buffer[0])->next = NULL;
	return new_root;
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
