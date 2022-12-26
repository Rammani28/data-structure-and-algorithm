// implementation of singly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
};

struct node *head=NULL;


//void create(){
//	int data;
//	struct node *newnode;
//	newnode = malloc(sizeof(struct node));
//	
//	printf("enter data: ");
//	scanf("%d", &data);
//	newnode->info = data;
//}


void insert_first(){
	int data;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	
	if (head==NULL){
		head = newnode;
	}else{
		newnode->next = head;
		head = newnode;
	}	
	printf("inserted %d\n",newnode->info);
	printf("next at newnode is %d\n", newnode->next);
}


void insert_end(){
	struct node *newnode;
	struct node *ptr;
	int data;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	newnode->next = NULL;
	
	if (head == NULL){
		head = newnode;
	}else{
		ptr = head;
		while(ptr->next!=NULL){///error here
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}


void insert_pos(){
	int i=0, data, pos;
	struct node *newnode;
	struct node *ptr;
	newnode = (struct node*)malloc(sizeof(struct node));

	printf("Enter data: ");
	scanf("%d", &data);
	newnode->info = data;
	
	printf("enter position: ");
	scanf("%d", &pos);
	
	for(i=0;i<pos-1;i++){
		ptr = ptr->next;
		if(ptr==NULL){
			printf("Position not found!");
		}
	}
	newnode->next = ptr->next;
	ptr->next = newnode;
}

void delete_first(){
	struct node *ptr;
		
	if(head==NULL){
		printf("void deletion.No list found!");
		exit(1);
	}else{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

void delete_end(){
	struct node *ptr, *temp;
	if (head==NULL){
		printf("list is empty! ");
	}
	else if (head->next ==NULL){
		ptr=head;
		head=NULL;
		printf("deleted element is %d ", ptr->info);
		free(ptr);
	}else{
		ptr = head;
		while(ptr->next!=NULL){ ////error here
			temp=ptr;
			ptr=ptr->next;
			printf("the deleted element is %d ", ptr->info);
		}
		free(ptr);
	}
}

void delete_pos(){ //not working
	int pos, i=0;
	struct node *ptr, *temp;
	
	printf("enter the position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("list is empty!");
	}
	if (pos == 0){
		ptr = head;
		head = head->next;
		printf("deleted element is %d ", ptr->info);
		free(ptr);
	}
	else{
		ptr = head;
		for(i=0;i<pos;i++){
			temp = ptr;
			ptr = ptr->next;
			if(ptr==NULL){
				printf("position not found");
				break;
			}
			temp->next=ptr->next;
		}
		
		free(ptr);
	}
}

void display(){
	struct node *temp;
	int i=0;
	temp = head;
	
	if(temp==NULL){
		printf("the list is empty!");
	}else{
		while(temp->next!=NULL){
			printf("displayed %d\n", temp->info);
			temp = temp->next;
		}
	}
}

int main(){
	insert_first();
	insert_first();
	display();
	
	return 0;
}
