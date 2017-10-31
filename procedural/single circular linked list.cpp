#include<iostream>
#include<conio.h>
using namespace std;

//structure 
struct node
{
	int ab;
	node *next;


};
//initlization

void initlize(struct node *head, int a) {
	head->ab = a;
	head->next = head;

}

//inert the values
void insert(struct node *head, int a) {
	struct node *q = new node;
	q->ab = a;
	q->next = head;
	node *p = head;

	while (p) {
		if (p->next == head) {
			p->next = q;
			break;
		}
		else {
			p = p->next;
		}
	}

}
//display the values 

void display(struct  node *head)
{
	node *p = head;
	
	do {
		cout << p->ab << endl;
		p = p->next;
	} while (p!=head);
}





void delet(struct node *head, int data) {//delete the given node as well as mantain the link

	node *p = head;


	if (head->ab == data) { //if in case head equals to given data
		//while (p->next != head) {
			//p = p->next;
		//}
	//	node *q = p;
		//p = p->next;
	//	head = head->next;
		initlize(head, head->next->ab);
		head->next = head->next->next;
		//p->next = head;
		
		//delete(q);//deteting the node


	}
	else
	{
        do {
			if (p->next->ab == data) {
				node *q = p->next;
				p->next = q->next;
				delete(q);//deleting the node
				break;
			}
			else {
				p = p->next;//moving to next node
			}
		} while (p != head);
	}
	}
void edit(struct node *head, int a, int c) {//edit ....over load the values 

	node *p = head;

	do{
		if (p->ab == a) {
			p->ab = c;
			break;
		}
		else {
			p = p->next;
		}
	}while (p->next!= head);
}

int main() {

	struct node *head = new node;
	//cout << "Enter Number" << endl;
	//int n;
//	cin >> n;
	//initlize(head, n);//initlize
	
	initlize(head, 10);//initlize
	insert(head, 15);//inserting the value 
	insert(head, 10);
	insert(head, 18);
	insert(head, 11);
	insert(head, 12);
	insert(head, 13);
	cout << "After insertion :" << endl;
	display(head);
	cout << "after deletetion" << endl;
	//delet(head,n);
	delet(head, 15);
	delet(head, 18);
	//delet(head, 10);
	edit(head, 10, 100);//Edit ..over load the value of 10 with 100
	display(head);
	_getch();
}

