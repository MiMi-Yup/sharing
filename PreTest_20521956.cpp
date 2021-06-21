#include <iostream>
#include <string>
using namespace std;

struct author {
	string name;
	string address;
	string nation;
};
struct paper {
	int ID;
	string name;
	int year;
	int n;
	author* authors;
};
struct NODE {
	paper Paper;
	NODE* next;
};

struct list {
	NODE* head;
	NODE* tail;
};

void init(list& list);
NODE* createNode();
bool find(list list, int ID);
void addHead(list& list, NODE* n);
void printNode(NODE* p);
void print(list list);
void search(list list, string name);
void removeHead(list& list);
void removeTail(list& list);
void remove_after(list& list, NODE* q);
bool removeValue(list& list, string address);

void change(NODE*& head, NODE* new_node);
void sortIncrease(list& list);

int menu();
bool exec(list& list, int mode = menu());

int main() {
	bool flag = false;
	list danhsach;
	init(danhsach);
	while (exec(danhsach));
	return(0);
}

void init(list& list) {
	list.head = NULL;
	list.tail = NULL;
}
NODE* createNode() {
	NODE* p = new NODE;
	if (p != NULL) {
		cout << "Nhap ma bai bao: "; cin >> p->Paper.ID;
		cin.ignore();
		cout << "Nhap ten bai bao: "; getline(cin, p->Paper.name);
		cout << "Nhap nam san xuat: "; cin >> p->Paper.year;
		cout << "Nhap so luong tac gia: "; cin >> p->Paper.n;
		cin.ignore();
		p->Paper.authors = new author[p->Paper.n];
		if (p->Paper.authors != NULL) {
			for (int i = 0; i < p->Paper.n; i++) {
				cout << "\nNhap tac gia thu " << i << " :\n";
				cout << "Nhap ten: "; getline(cin, p->Paper.authors[i].name);
				cout << "Nhap noi cong tac: "; getline(cin, p->Paper.authors[i].address);
				cout << "Nhap quoc gia: "; getline(cin, p->Paper.authors[i].nation);
			}
		}
		p->next = NULL;
	}
	return p;
}
bool find(list list, int ID) {
	if (list.head != NULL) {
		NODE* p = list.head;
		while (p != NULL
			&& p->Paper.ID != ID) {
			p = p->next;
		}
		if (p == NULL)return false;
		else return true;
	}
	return false;
}
void addHead(list& list, NODE* n) {
	if (list.head == NULL) {
		list.head = n;
		list.tail = n;
	}
	else {
		if (!find(list, n->Paper.ID)) {
			n->next = list.head;
			list.head = n;
		}
		else cout << "Ma bai bao " << n->Paper.ID << " da ton tai trong danh sach.\n";
	}
}
void printNode(NODE* p) {
	if (p != NULL) {
		cout << "======================================\n";
		cout << "Ma bai bao: " << p->Paper.ID << "\n";
		cout << "Ten bai bao: " << p->Paper.name << "\n";
		cout << "Nam san xuat: " << p->Paper.year << "\n";
		if (p->Paper.authors != NULL) {
			for (int i = 0; i < p->Paper.n; i++) {
				cout << "\nTac gia thu " << i << " :\n";
				cout << "Ten: " << p->Paper.authors[i].name << "\n";
				cout << "Noi cong tac: " << p->Paper.authors[i].address << "\n";
				cout << "Quoc gia: " << p->Paper.authors[i].nation << "\n";
			}
		}
		cout << "======================================\n";
	}
}
void print(list list) {
	NODE* p = list.head;
	while (p != NULL) {
		printNode(p);
		p = p->next;
	}
}
void search(list list, string name) {
	NODE* p = list.head;
	while (p != NULL) {
		for (int i = 0; i < p->Paper.n; i++) {
			if (p->Paper.authors[i].name.compare(name) == 0) {
				printNode(p);
				break;
			}
		}
		p = p->next;
	}
}
void removeHead(list& list) {
	if (list.head != NULL) {
		NODE* p = list.head;
		if (list.head->next != NULL) {
			list.head = list.head->next;
		}
		else {
			list.head = NULL;
			list.tail = NULL;
		}
		delete p;
		p = NULL;
	}
}
void removeTail(list& list) {
	if (list.head != NULL) {
		NODE* p = list.tail;
		if (list.head->next != NULL) {
			NODE* k = list.head;
			while (k->next != p) {
				k = k->next;
			}
			k->next = NULL;
			list.tail = k;
		}
		else {
			list.head = NULL;
			list.tail = NULL;
		}
		delete p;
		p = NULL;
	}
}
void remove_after(list& list, NODE* q) {
	NODE* p;
	if (q != NULL) {
		p = q->next;
		if (p != NULL) {
			//q->next = p->next;
			if (p == list.tail) {
				list.tail = q;
				q->next = NULL;
			}
			else q->next = p->next;
			delete p;
			p = NULL;
		}
	}
}
bool removeValue(list& list, string address) {
	NODE* p = list.head, * q = NULL;
	while (p != NULL) {
		for (int i = 0; i < p->Paper.n; i++) {
			if (p->Paper.authors[i].address.compare(address) == 0) {
				if (p == list.head) {
					removeHead(list);
					p = list.head;
					continue;
				}
				else if (p == list.tail) {
					removeTail(list);
					p = list.tail;
				}
				else {
					remove_after(list, q);
					p = q;
				}
				break;
			}
		}
		q = p;
		p = p->next;
	}
	return true;
}

void change(NODE*& head, NODE* new_node) {
	NODE* current;
	if (head == NULL || head->Paper.year >= new_node->Paper.year)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		current = head;
		while (current->next != NULL && current->next->Paper.year < new_node->Paper.year)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
void sortIncrease(list& list) {
	NODE* sorted = NULL;
	NODE* current = list.head;
	while (current != NULL)
	{
		NODE* next = current->next;
		change(sorted, current);
		current = next;
	}
	list.head = sorted;
}

int menu() {
	int temp;
	do {
		system("cls");
		cout << "1. Nhap vao danh sach va xuat.\n";
		cout << "2. Tim cac bai bao co ten tac gia X viet.\n";
		cout << "3. Sap xep cac bai bao theo nam.\n";
		cout << "4. Xoa cac bai bao co tac gia cong tac tai X.\n";
		cout << "5. Thoat chuong trinh.";
		cout << "\n\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 1 || temp>5) {
			cout << "Khong hop le, nhap lai.\n";
			system("pause");
		}
	} while (temp < 1 || temp>5);
	cin.ignore();
	return temp;
}
bool exec(list& list, int mode) {
	system("cls");
	int n; string temp;
	switch (mode)
	{
	case 1:
		cout << "Nhap so luong bai bao can them: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			addHead(list, createNode());
		}
		cout << "Danh sach bai bao:\n";
		print(list);
		break;
	case 2:
		cout << "Nhap ten tac gia X: ";
		getline(cin, temp);
		search(list, temp);
		break;
	case 3:
		sortIncrease(list);
		cout << "Danh sach bai bao sau khi da sap xep theo nam:\n";
		print(list);
		break;
	case 4:
		cout << "Nhap noi cong tac X:\n";
		getline(cin, temp);
		removeValue(list, temp);
		break;
	case 5:
		return false;
	default:
		cout << "Nhap thu tu khong hop le.\n";
		break;
	}
	system("pause");
	return true;
}

