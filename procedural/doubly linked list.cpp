#include<iostream>
#include<conio.h>
using namespace std;


struct node
 { 
	
	int ab;
	node *next;
	node *prv;

};
//initilazition

void initlize(struct node *head, int a) {
	head->ab = a;
	head->next = NULL;
	head->prv = NULL;
}


void initlize(struct node *head, struct node *q) {

	if (!q) {

		head->ab =NULL;
		head->next = NULL;
		head->prv = NULL;
	}
	else
	{
		head->ab = q->ab;
		head->next = q->next;
		head->prv = q->prv;

	}

	


}

//insert
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = NULL;
	q->prv = NULL;
	node *p = head;
	if (head->ab == NULL) {
		initlize(head, a);
	}
	else
	{
	while (p) {
			if (p->next == NULL) {
				p->next = q;//assining the give node at the end 
				p->next->prv = p;//saving the address of previs node in last node 
				return;
			}
			else {
				p = p->next;
			}
		}
	}
}
//reverse
void revers(struct node *head) {
	
	node *p = head;

	while (p) {
		if (p->next == NULL) {
			while (p)
			{
				if (p->prv== NULL) {
					cout << p->ab << endl;
					break;
				}
				else
				{
					cout << p->ab<<endl;
					p = p->prv;
				}

			}
			break;
		}
		else {
			p = p->next;
		}
	}

}


//display
void display(struct  node *head)
{
	node *p = head;
	if (p->ab==NULL) {
		cout<<"Stack si empty"<<endl;
	}
	else
	{
		while (p) {
			cout << p->ab << endl;
			p = p->next;
		}
	}
	
}
//delete
void delet(struct node *head, int a) {

	node *p = head;
	node *q;
	if (head->ab == a) {
		q = head->next;
		//head = head->next;
		initlize(head, q);
	
	}
	else
	{
	while (p) {
			if (p->next->ab == a) {
				if (p->next->next!= NULL) {
					p->next = p->next->next; //skipping the node which value is equal to given number---and assing the addres of next node
					p->next->prv = p;//saving the address of p in the next moved node
				}
				else
				{
					p->next = NULL;
					
				}
				break;
			}
			else {
				p = p->next;
			}
		}
	}
}

//edit
void edit(struct node *head, int a, int c) {

	node *p = head;

	while (p) {
		if (p->ab == a) {
			p->ab = c;
			return;
		}
		else {
			p = p->next;
		}
	}
}

int main() {

	struct node *head = new node;
	cout << "Enter Number" << endl;
	int n;
	cin >> n;
	initlize(head, n);
	insert(head, 15);
	insert(head, 10);
	insert(head, 18);
	cout << "After inputr the data"<<endl; display(head);
//	cout << "Revers order of input" << endl;	revers(head);
	
	
delet(head, n);
	delet(head, 18);
	delet(head, 15);
	delet(head, 10);
	cout << "After deleting the data 18" << endl; display(head);

	edit(head, 10, 100);
	cout << "After editing  the data 10 to 100" << endl; display(head);
	
	
	_getch();
}

