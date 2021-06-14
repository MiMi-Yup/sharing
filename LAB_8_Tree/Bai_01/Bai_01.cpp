#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
typedef node* tree;
void init(tree& tree);
node* createNode(int data);

int createBinarySearchTree(tree& tree, int data);
node* BinarySearchTree(tree tree, int x);

void print_NLR(tree tree);
void print_LRN(tree tree);
void print_arr(int* arr, int n);
void print_child(tree tree, int data);

bool prime(int n);
void print_prime(tree tree);

bool find(tree tree, int data);

int count_node(tree tree);
void transform(tree tree, int* arr, int& n);
int* tree2array(tree tree, int& n);

void selection_sort(int* arr, int n);

int menu();
bool exec(tree& tree, int mode = menu());

int main() {
	tree tree;
	init(tree);
	while (exec(tree));
	return(0);
}

void init(tree& tree) {
	tree = NULL;
}
node* createNode(int data) {
	node* p = new node;
	if (p != NULL) {
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

int createBinarySearchTree(tree& tree, int data) {
	if (tree != NULL) {
		if (tree->data == data)return 0;
		if (tree->data > data)return createBinarySearchTree(tree->left, data);
		else return createBinarySearchTree(tree->right, data);
	}
	else {
		tree = createNode(data);
		if (tree == NULL)return -1;
		return 1;
	}
}
node* BinarySearchTree(tree tree, int x) {
	if (tree != NULL) {
		if (tree->data == x)return tree;
		if (tree->data > x)return BinarySearchTree(tree->left, x);
		return BinarySearchTree(tree->right, x);
	}
	return NULL;
}

void print_NLR(tree tree) {
	if (tree != NULL) {
		cout << tree->data << " ";
		print_NLR(tree->left);
		print_NLR(tree->right);
	}
}
void print_LRN(tree tree) {
	if (tree != NULL) {
		print_LRN(tree->left);
		print_LRN(tree->right);
		cout << tree->data << " ";
	}
}
void print_arr(int* arr, int n) {
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

bool prime(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return true;
}
void print_prime(tree tree) {
	if (tree != NULL) {
		print_prime(tree->left);
		if (prime(tree->data))cout << tree->data << " ";
		print_prime(tree->right);
	}
}

void print_1child(tree tree) {
	if (tree != NULL) {
		print_1child(tree->right);
		print_1child(tree->left);
		if ((tree->left == NULL && tree->right != NULL) || (tree->right == NULL && tree->left != NULL))cout << tree->data << " ";
	}
}

bool find(tree tree, int data) {
	return (BinarySearchTree(tree, data) != NULL ? true : false);
}

int count_node(tree tree) {
	if (tree != NULL) {
		return 1 + count_node(tree->left) + count_node(tree->right);
	}
	return 0;
}
void transform(tree tree, int* arr, int& n) {
	if (tree != NULL && arr != NULL) {
		transform(tree->left, arr, n);
		transform(tree->right, arr, n);
		arr[n] = tree->data;
		n++;
	}
}
int* tree2array(tree tree, int& n) {
	n = count_node(tree);
	int i = 0;
	int* arr = new int[n];
	transform(tree, arr, i);
	return arr;
}

void selection_sort(int* arr, int n) {
	if (arr != NULL) {
		for (int i = 0; i < n - 1; i++) {
			int min = arr[i], index = i;
			for (int j = i + 1; j < n; j++) {
				if (min > arr[j]) {
					index = j;
					min = arr[j];
				}
			}
			min = arr[index];
			arr[index] = arr[i];
			arr[i] = min;
		}
	}
}

int menu() {
	int temp;
	do {
		::system("cls");
		cout << "\nVui long chon chuc nang.";
		cout << "\n0. Nhap vao cay nhi phan tim kiem."
			<< "\n1. In ra cay."
			<< "\n2. Nhung node trong cay co 1 cay con."
			<< "\n3. Kiem tra X co trong cay."
			<< "\n4. In so nguyen to co trong cay."
			<< "\n5. Chuyen doi cay -> mang. Sau do sap xep."
			<< "\n6. Thoat chuong trinh.";
		cout << "\n\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 0 || temp>6) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (temp < 0 || temp>6);
	return temp;
}
bool exec(tree& tree, int mode) {
	::system("cls");
	int x, temp, * arr = NULL;
	bool flag;
	switch (mode)
	{
	case 0:
		cout << "Nhap so luong phan tu muon dua vao cay: ";
		cin >> x;
		for (int i = 0; i < x; i++) {
			cout << "Phan tu thu " << i << ": ";
			cin >> temp;
			switch (createBinarySearchTree(tree, temp))
			{
			case 0:
				cout << "Da co phan tu " << temp << " trong cay.\n";
				break;
			case -1:
				cout << "Khong the cap phat them bo nho.\n";
			default:
				break;
			}
		}
		break;
	case 1:
		cout << "NLR: "; print_NLR(tree); cout << endl;
		break;
	case 2:
		cout << "Nhung node trong cay co 1 cay con: ";
		print_1child(tree);
		cout << "\n";
		break;
	case 3:
		cout << "Nhap gia tri X: ";
		cin >> temp;
		if (find(tree, temp)) {
			cout << "Tim thay gia tri " << temp << " trong cay\n";
		}
		else cout << "Khong tim thay gia tri " << temp << " trong cay\n";
		break;
	case 4:
		cout << "Cac so nguyen to co trong cay la: ";
		print_prime(tree);
		cout << endl;
		break;
	case 5:
		arr = tree2array(tree, temp);
		if (arr != NULL) {
			print_arr(arr, temp);
			cout << "Mang sau khi sap sep: ";
			selection_sort(arr, temp);
			print_arr(arr, temp);
			delete arr;
		}
		break;
	case 6:
		return false;
	default:
		cout << "Khong hop le.";
		break;
	}
	::system("pause");
	return true;
}