#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};

void
print_elem(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

struct node *
insert(struct node **head, int data)
{
	struct node *new_node = malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
	}
	else {
		struct node *temp = *head;
		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new_node;
	}

	return new_node;
}

void
remove_elem(struct node **head, int data)
{
	struct node *temp = *head;
	struct node *prev = *head;

	if (temp == NULL) {
		printf("Error: List is empty\n");
		return;
	}

	while(temp != NULL) {
		if (temp->data == data) {
			if (temp == *head) {
				*head = temp->next;
			}
			else {
				prev->next = temp->next;
			}
	
			free(temp);
			break;
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
}


int main()
{
	struct node *head = NULL;

	(void)insert(&head, 2);

	(void)insert(&head, 4);

	print_elem(head);

	remove_elem(&head, 2);

	print_elem(head);

	(void)insert(&head, 6);

	(void)insert(&head, 9);

	(void)insert(&head, 10);

	(void)insert(&head, 44);

	print_elem(head);

	remove_elem(&head, 10);

	remove_elem(&head, 10);

	print_elem(head);

	return 0;
}