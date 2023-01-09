#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int info;
	struct node *next;
	struct node *prev;
};
struct node *head = NULL;
 
void insert_first(){
	int data;
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	newnode->prev = NULL;
	newnode->next = NULL;
 
	if (head==NULL){
		head=newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
 
}
 
void insert_end(){
	int data;
	struct node *newnode, *ptr;
	newnode = (struct node *) malloc(sizeof(struct node));
 
	printf("enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	newnode->prev = NULL;
	newnode->next = NULL;
 
	if (head==NULL){
		head = newnode;
	}
	else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next=newnode;
		newnode->prev = ptr;
	}
}
 
void insert_pos(){//not working
	int i=0, data, pos;
	struct node *newnode, *ptr;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	newnode->prev = NULL;
	newnode->next = NULL;
 
	printf("enter the position: ");
	scanf("%d", &pos);
 
	ptr = head;
	for(i=0; i<pos-1;i++){
		ptr = ptr->next;
		if(ptr==NULL){
			printf("position not found! ");
			break;
		}
	}
	newnode->next = ptr->next;
	newnode->prev = ptr;
	ptr->next->prev=newnode;
	ptr->next = newnode;
}
 
void delete_first(){
	struct node *ptr;
	if(head == NULL){
		printf("no list found! ");
		return;
	}
	else{
		ptr = head;
		head = head->next;
		head ->prev = NULL;
		printf("deleted %d ", ptr->info);
		free(ptr);
	}
}
 
void delete_end(){
	struct node *ptr;
	if (head == NULL){
		printf("no list found! ");
		return;
	}
	else if(head->next == NULL){
		ptr = head;
		head = NULL;
		printf("deleted %d \n", ptr->info);
		free(ptr);
	}
	else{
		ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		printf("deleted %d \n", ptr->info);
		free(ptr);
	}
}
 
void delete_pos(){
	struct node *ptr;
	int pos, i=0;
 
	printf("enter pos: ");
	scanf("%d", &pos);
 
	if (head==NULL){
		printf("no list found! ");
		return;
	}
	else if(pos==0){
		ptr=head;
		head=head->next;
		head->prev=NULL;
		printf("deleted %d", ptr->info);
		free(ptr);
	}
	else{
		ptr = head;
		for (i=0; i<pos;i++){
			ptr=ptr->next;
			if(ptr==NULL){
				printf("position not found! ");
				return;
			}
		}
		printf("deleted %d \n", ptr->info);
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
 
		free(ptr);
	}
	return;
}
 
void display(){
	struct node *ptr;
	printf("the elements in list are: ");
	ptr = head;
	while(ptr!=NULL){
		printf("\n%d", ptr->info);
		ptr=ptr->next;
	}
	return;
}
 
 
int main(){
	insert_first();
	insert_first();
 
	return 0;
}
 
