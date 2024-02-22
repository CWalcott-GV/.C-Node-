#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  char name[10];
  char unit[10];
  int price;
  int quantity;
  struct node *next;
}node;

struct node *add(node*,char*,char*,int,int);
void removeNode(node**,char*);
void printElements(node*); 

/*	Corey Walcott, Daniel Brillhart. Project 2. Shopping command line GUI.

	3/25/2022
*/


//struct node* make(){
	//struct node* head = NULL;
	//	return head;
//}

node *add(node* head, char* a, char* b, int c, int d) {
    node *newNode = (node *) malloc (sizeof(node));
    strcpy(newNode->name,a);
    strcpy(newNode->unit,b);
    newNode->price = c;
    newNode->quantity = d;
    newNode->next = head;
    head = newNode;
    return head;
}

void removeNode(node **head,char* find) {
  	
    node *temp = *head, *prev;
    if(temp != NULL && strcmp(temp->name,find)==0){
		*head = temp->next;
		free(temp);
		return;
	}
	/*
	while (temp != NULL){
	     	if(strcmp(temp->name,find) == 0){
	     		if(temp == head){
	     		head = temp->next;
     		}
     		else{
     			prev->next = temp->next;
     		}
		prev = temp;
		temp = temp->next;	
		}
	
      	}

	}
	*/
	
	while (temp != NULL && temp->name != find) {
        prev = temp;
        temp = temp->next;
    	}
	
	if(temp == NULL)
		return;
		
	prev->next = temp->next;
	
	free(temp);
	return;
}
void printElements(node *head) {

  node *aux = head;
  if(head == NULL){
		printf("List is empty\n");
		}
  while(aux != NULL) {
    printf("%s ",aux->name);
    printf("%s ",aux->unit);
    printf("%d ",aux->price);
    printf("%d ",aux->quantity);
    printf("\n");
    aux = aux->next;
  }
}


void buy(node *head, char *name){
	if(head == NULL){
	printf("No list, create list first.\n");
	return;
	}
	else{
		node* temp = head;
		while(temp != NULL) {
			if(strcmp(temp->name, name) == 0){
			int buy = temp -> quantity;
			buy = buy + 1;
			temp -> quantity = buy;
			printf("Item has be purchased.\n");
			return;
			}
		else{
			temp = temp -> next;
		}
	}
printf("Item does not exist.\n");
}
}


void sell(node *head, char *name) {
	if(head == NULL) {
		printf("No list, create list first.\n");
		return;
	}
		else{
		node *temp = head;
			while(temp != NULL) {
				if(strcmp(temp -> name, name) == 0){
					int sell = temp -> quantity;
					sell = sell - 1;
					if(sell = 0){
						printf("item now has quantity less than zero\n");
					}
					temp -> quantity = sell;
					printf("Item has be sold.\n");
					return;
				}
				else{
				temp = temp -> next;
				}
			}
		printf("Item does not exist.\n");
		}

}

void deleteList(struct node** head){
	struct node* prev = *head;
	
	while(*head){
		*head = (*head) -> next;
		
		free(prev);
		prev = *head;
	}
}

bool search(node* head, char* name)
{
    node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->name, name)==0)
            return true;
        current = current->next;
    }
    return false;
}


int main()
{
 int num;
 char name[10] = "a";
 char unit[10] = "b";
 int quantity = 0;
 int price = 0;
 char temp;

  //make();
  node* head = NULL;
  while(1){

	printf("Commands: \n 1: Create Empty List\n 2: Insert a product\n 3: Delete a product\n 4: Delete Entire List\n 5: Search a product\n 6: Display products in list\n 7: Purchase a product\n 8: Sell a product\n 0: Exit\n");

    	if (scanf("%d", &num) != 1) {
            printf(" *Error: Invalid input. Press try again.\n");
            scanf("%s", &temp); /*this will clear the input buffer */
            continue;
        }
    	

	switch(num) {
    		case 1:{
        		//make();
        		printf("Case 1:\n");
        		break;
    		}

    		case 2:{
		    	printf("Input Syntax: Name, unit, quantity, price\n");
		    	scanf("%s %s %d %d", name, unit, &quantity, &price);
			head = add(head, name, unit, quantity, price);
        		break;
    		}

    case 3:{
    	printf("Input Syntax: Name\n");
    	scanf("%s", name);
        removeNode(&head,name);
	printf("%s removed...\n", name);
        break;
        }

    case 4:{
        printf("Are you sure you want to delete the whole list? y or n?\n");
        char choice[1];
        scanf("%s", choice);
        if(choice[0] == 'y')
        	deleteList(&head);
        break;
    }
    case 5:{
    	printf("Enter your search name: \n");
    	scanf("%s", name);
    	if(search(head,name) == true){
    		printf("%s was found!\n", name);
    	}
    	else{
    		printf("%s was not found!\n",name);
    	}
        break;
    }

    case 6:{
        printElements(head);
        break;
    }

    case 7 :{
    	printf("Input Syntax: Name\n");
    	scanf("%s", name);
        buy(head,name);
        break;
    }

    case 8:{
    	printf("Input Syntax: Name\n");
    	scanf("%s", name);
        sell(head,name);
        break;
    }

    case 9:{
    printf("Case 9:\n");
        //*();
        break;
    }

    case 0:{
    	return 0;
        break;
    }
    default:{
    	printf("input not a single number\n");
    	break;
    	}
    	} //end of switch
    }	//end of while
    
 return 0;

} //end of main




