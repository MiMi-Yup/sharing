#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#define MIN 1
#define MAX 500
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

node* minValueNode(tree p);
node* maxValueNode(tree p);

void print_NLR(tree tree);
void print_NRL(tree tree);
void print_LNR(tree tree);
void print_LRN(tree tree);
void print_RNL(tree tree);
void print_RLN(tree tree);

void depth_print(node* p, int level);

int random(int min, int max);
int* generator(int n);
bool insertTree(int* arr, int n, tree& tree);
void print_arr(int* arr, int n);

bool prime(int n);
void print_prime(tree tree);
node* max_prime(tree tree);

int sum_branch_left(tree tree);
int count_compare(tree tree, int x, int y = 0);

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

node* minValueNode(tree p) {
	node* current = p;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
node* maxValueNode(tree p) {
	node* current = p;
	while (current && current->right != NULL)
		current = current->right;
	return current;
}

void print_NLR(tree tree) {
	if (tree != NULL) {
		cout << tree->data << " ";
		print_NLR(tree->left);
		print_NLR(tree->right);
	}
}
void print_NRL(tree tree) {
	if (tree != NULL) {
		cout << tree->data << " ";
		print_NRL(tree->right);
		print_NRL(tree->left);
	}
}
void print_LNR(tree tree) {
	if (tree != NULL) {
		print_LNR(tree->left);
		cout << tree->data << " ";
		print_LNR(tree->right);
	}
}
void print_LRN(tree tree) {
	if (tree != NULL) {
		print_LRN(tree->left);
		print_LRN(tree->right);
		cout << tree->data << " ";
	}
}
void print_RNL(tree tree) {
	if (tree != NULL) {
		print_RNL(tree->right);
		cout << tree->data << " ";
		print_RNL(tree->left);
	}
}
void print_RLN(tree tree) {
	if (tree != NULL) {
		print_RLN(tree->right);
		print_RLN(tree->left);
		cout << tree->data << " ";
	}
}

void depth_print(node* p, int level) {
	if (p != NULL) {
		if (level == 0)cout << p->data << " ";
		else {
			depth_print(p->left, level - 1);
			depth_print(p->right, level - 1);
		}
	}
}

int random(int min, int max) //range : [min, max]
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}
int* generator(int n) {
	int* arr = new int[n];
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			*(arr + i) = random(MIN, MAX);
		}
	}
	return arr;
}
bool insertTree(int* arr, int n, tree& tree) {
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			switch (createBinarySearchTree(tree, *(arr + i)))
			{
			case 0:
				cout << "Da co phan tu " << *(arr + i) << " trong cay.\n";
				break;
			case -1:
				cout << "Khong the cap phat them bo nho.\n";
				return false;
			default:
				break;
			}
		}
		return true;
	}
	return false;
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
node* max_prime(tree tree) {
	static node* temp = NULL;
	if (tree != NULL) {
		if ((temp = max_prime(tree->right)) != NULL) {
			return temp;
		}
		if (prime(tree->data))return tree;
		if ((temp = max_prime(tree->left)) != NULL)return temp;
	}
	return NULL;
}
int sum_branch_left(tree tree) {
	if (tree != NULL) {
		return (tree->data % 2 == 0 ? tree->data : 0) + sum_branch_left(tree->left) + sum_branch_left(tree->right);
	}
	return 0;
}
int count_compare(tree tree, int x, int y) {
	if (tree != NULL) {
		return ((tree->data < x) && (tree->data > y) ? 1 : 0) + count_compare(tree->left, x, y) + count_compare(tree->right, x, y);
	}
	return 0;
}
void print_arr(int* arr, int n) {
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			cout << *(arr + i) << " ";
		}
	}
}
int menu() {
	int temp;
	do {
		::system("cls");
		cout << "\nVui long chon chuc nang.";
		cout << "\n1. Nhap vao cay nhi phan tim kiem."
			<< "\n2. Cac so nguyen to co trong cay."
			<< "\n3. So nguyen to lon nhat."
			<< "\n4. In ra cac node o muc K."
			<< "\n5. Tong so chan ben cay con trai."
			<< "\n6. Phan tu nho nhat ben cay con phai."
			<< "\n7. Phan tu lon nhat ben cay con trai."
			<< "\n8. So node co gia tri nho hon x."
			<< "\n9. So node co gia tri lon hon x va nho hon y."
			<< "\n10. Thoat chuong trinh.";
		cout << "\n\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 1 || temp>10) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (temp < 1 || temp>10);
	return temp;
}
bool exec(tree& tree, int mode) {
	::system("cls");
	int x, y;
	static int* arr = NULL;
	static node* temp = NULL;
	switch (mode)
	{
	case 1:
		cout << "Nhap so luong phan tu muon dua vao cay: ";
		cin >> x;
		arr = generator(x);
		cout << "Trong mang moi random co phan tu: "; print_arr(arr, x); cout << endl;
		if (insertTree(arr, x, tree)) {
			cout << "Da nhap phan tu tu mang vao cay thanh cong.\n";
		}
		else cout << "Nhap phan tu tu mang vao cay khong thanh cong.\n";
		cout << "LNR: "; print_LNR(tree); cout << endl;
		cout << "LRN: "; print_LRN(tree); cout << endl;
		cout << "NLR: "; print_NLR(tree); cout << endl;
		cout << "NRL: "; print_NRL(tree); cout << endl;
		cout << "RNL: "; print_RNL(tree); cout << endl;
		cout << "RLN: "; print_RLN(tree); cout << endl;
		break;
	case 2:
		cout << "Cac so nguyen to co trong cay la: ";
		print_prime(tree); cout << endl;
		break;
	case 3:
		if (temp = max_prime(tree)) {
			cout << "So nguyen to lon nhat trong cay la: " << temp->data << "\n";
		}
		else cout << "Khong co so nguyen to trong cay.\n";
		break;
	case 4:
		cout << "Nhap muc K: ";
		cin >> x;
		cout << "Muc " << x << " :";
		depth_print(tree, x);
		cout << endl;
		break;
	case 5:
		cout << "Tong so chan ben cay con trai: " << sum_branch_left(tree->left) << endl;
		break;
	case 6:
		if (tree != NULL && tree->right != NULL) {
			cout << "Gia tri nho nhat cua cay con phai cua cay: " << minValueNode(tree->right)->data << endl;
		}
		else cout << "Cay trong.\n";
		break;
	case 7:
		if (tree != NULL && tree->left != NULL) {
			cout << "Gia tri lon nhat cua cay con trai cua cay: " << maxValueNode(tree->left)->data << endl;
		}
		else cout << "Cay trong.\n";
		break;
	case 8:
		cout << "Nhap gia tri x: ";
		cin >> x;
		cout << "So luong node co gia tri nho hon " << x << " la: " << count_compare(tree, x) << endl;
		break;
	case 9:
		cout << "Nhap gia tri x: ";
		cin >> x;
		cout << "Nhap gia tri y: ";
		cin >> y;
		cout << "So luong node co gia tri lon hon " << x << " va nho hon " << y << "  la: " << count_compare(tree, y, x) << endl;
		break;
	case 10:
		return false;
	default:
		cout<<"Khong hop le.\n";
		break;
	}
	::system("pause");
	if (arr != NULL) {
		delete arr;
		arr = NULL;
	}
	return true;
}