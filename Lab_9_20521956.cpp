#include <iostream>
using namespace std;
#define M 11

int N = 0;
struct node {
	int data;
	node* next;
	node(int key) {
		data = key;
		next = NULL;
	}
};

void init(node* hashtable[]);
void destroy(node* hashtable[]);
int F1(int key);
int F2(int key);
bool search_linear(node* hashtable[], int(*function)(int key), int key);
bool search_quad(node* hashtable[], int(*function)(int key), int key);
bool search_linked(node* hashtable[], int(*function)(int key), int key);
void insertHash_linear(node* hashtable[], int(*function)(int key), int key);
void insertHash_quad(node* hashtable[], int(*function)(int key), int key);
void insertHash_linked(node* hashtable[], int(*function)(int key), int key);
void print(node* hashtable[]);
int menu();
int hash_menu();
bool exec(node* hashtable[], int arr[], int n, int mode = menu());

int main() {
	int arr[] = { 32,15,25,44,36,21,15 };
	int n = sizeof(arr) / sizeof(int);
	node* hashtable[M];
	init(hashtable);
	while (exec(hashtable, arr, n));
	return(0);
}

void init(node* hashtable[]) {
	for (int i = 0; i < M; i++) {
		hashtable[i] = NULL;
	}
	N = 0;
}
void destroy(node* hashtable[]) {
	for (int i = 0; i < M; i++) {
		while (hashtable[i] != NULL) {
			node* p = hashtable[i];
			hashtable[i] = p->next;
			delete p;
		}
	}
}
int F1(int key) {
	return key % M;
}
int F2(int key) {
	return (M - 2) - key % (M - 2);
}
bool search_linear(node* hashtable[], int(*function)(int key), int key) {
	int index = (*function)(key);
	while (hashtable[index] != NULL
		&& hashtable[index]->data != key) {
		index = (index + 1) % M;
	}
	if (hashtable[index] == NULL)return false;
	return true;
}
bool search_quad(node* hashtable[], int(*function)(int key), int key) {
	int index = (*function)(key);
	int i = 1;
	while (hashtable[index] != NULL
		&& hashtable[index]->data != key) {
		index = ((*function)(key) + i * i) % M;
		i++;
	}
	if (hashtable[index] == NULL)return false;
	return true;
}
bool search_linked(node* hashtable[], int(*function)(int key), int key) {
	node* p = hashtable[(*function)(key)];
	while (p != NULL
		&& p->data != key) {
		p = p->next;
	}
	if (p == NULL)return false;
	return true;
}
void insertHash_linear(node* hashtable[], int(*function)(int key), int key) {
	if (search_linear(hashtable, (*function), key))return;
	int index = (*function)(key);
	while (hashtable[index] != NULL) {
		index = (index + 1) % M;
	}
	hashtable[index] = new node(key);
	N++;
}
void insertHash_quad(node* hashtable[], int(*function)(int key), int key) {
	if (search_quad(hashtable, (*function), key) || N >= M - 1)return;
	int index = F1(key);
	int i = 1;
	while (hashtable[index] != NULL) {
		index = ((*function)(key) + i * i) % M;
		i++;
	}
	hashtable[index] = new node(key);
	N++;
}
void insertHash_linked(node* hashtable[], int(*function)(int key), int key) {
	if (search_linked(hashtable, (*function), key))return;
	int index = (*function)(key);
	node* p = hashtable[index];
	if (p == NULL) {
		hashtable[index] = new node(key);
		return;
	}
	while (p->next != NULL
		&& p->data != key) {
		p = p->next;
	}
	if (p->next == NULL)p->next = new node(key);
}
void print(node* hashtable[]) {
	cout << "Key Value\n";
	for (int i = 0; i < M; i++) {
		cout << i << " ";
		if (hashtable[i] != NULL) {
			node* p = hashtable[i];
			while (p != NULL) {
				cout << p->data << " ";
				p = p->next;
			}
		}
		else cout << "NULL";
		cout << endl;
	}
	cout << endl;
}
int menu() {
	int choose;
	do {
		::system("cls");
		cout << "1. Bam bang phuong phap tham do tuyen tinh.\n";
		cout << "2. Bam bang phuong phap tham do binh phuong.\n";
		cout << "3. Bam bang phuong phap bang bam day chuyen.\n";
		cout << "4. Thoat chuong trinh.\n";
		cout << "Lua chon cua ban: \n";
		cin >> choose;
		if (choose < 1 || choose>4) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (choose < 1 || choose>4);
	return choose;
}
int hash_menu() {
	int choose;
	do {
		::system("cls");
		cout << "1. Dung ham bam: F1(key) = key % M.\n";
		cout << "2. Dung ham bam: F2(key) = (M - 2) - key % (M - 2).\n";
		cout << "Lua chon cua ban: \n";
		cin >> choose;
		if (choose < 1 || choose>2) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (choose < 1 || choose>2);
	return choose;
}
bool exec(node* hashtable[], int arr[], int n, int mode) {
	::system("cls");
	int hash = 0;
	if (mode != 4) hash = hash_menu();
	switch (mode)
	{
	case 1:
		destroy(hashtable);
		init(hashtable);
		for (int i = 0; i < n; i++) {
			insertHash_linear(hashtable, hash == 1 ? F1 : F2, arr[i]);
		}
		print(hashtable);
		break;
	case 2:
		destroy(hashtable);
		init(hashtable);
		for (int i = 0; i < n; i++) {
			insertHash_quad(hashtable, hash == 1 ? F1 : F2, arr[i]);
		}
		print(hashtable);
		break;
	case 3:
		destroy(hashtable);
		init(hashtable);
		for (int i = 0; i < n; i++) {
			insertHash_linked(hashtable, hash == 1 ? F1 : F2, arr[i]);
		}
		print(hashtable);
		break;
	case 4:
		return false;
	default:
		break;
	}
	::system("pause");
	return true;
}