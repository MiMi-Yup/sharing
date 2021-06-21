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
int search(tree tree, int data);
int height_BST(tree tree);
int depth(tree tree, int data);
void level(tree BST, tree root);
int _rank(tree tree);
void rank_of_level(tree BST, tree root, int level);
void print_RNL(tree tree);
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

int search(tree tree, int data) {
	node* p = tree;
	node* q = p;
	while (p != NULL) {
		if (data < p->data) {
			q = p;
			p = p->left;
		}
		else if (data > p->data) {
			q = p;
			p = p->right;
		}
		else {
			if (p == q)return 1;
			else return q->data;
		}
	}
	return 0;
}

int height_BST(tree tree) {
	//height := height_BST - 1
	if (tree != NULL) {
		return 1 + max(height_BST(tree->left), height_BST(tree->right));
	}
	return 0;
}

int depth(tree tree, int data) {
	if (tree != NULL && tree->data != data) {
		if (tree->data > data) {
			return 1 + depth(tree->left, data);
		}
		else return 1 + depth(tree->right, data);
	}
	return 0;
}

void level(tree BST, tree root) {
	if (BST != NULL) {
		level(BST->left, root);
		cout << depth(root, BST->data) << " ";
		level(BST->right, root);
	}
}

int _rank(tree tree) {
	if (tree != NULL) {
		if (tree->left != NULL) {
			if (tree->right != NULL) {
				return 2;
			}
			return 1;
		}
		else if (tree->right != NULL) {
			return 1;
		}
		else return 0;
	}
	return -1;
}

void rank_of_level(tree BST, tree root, int level) {
	if (BST != NULL) {
		rank_of_level(BST->right, root, level);
		if (depth(root, BST->data) == level + 1) {
			cout << _rank(BST) << " ";
		}
		rank_of_level(BST->left, root, level);
	}
}

void print_RNL(tree tree) {
	if (tree != NULL) {
		print_RNL(tree->right);
		cout << tree->data << " ";
		print_RNL(tree->left);
	}
}

int menu() {
	int temp;
	do {
		system("cls");
		cout << "Vui long chon chuc nang.\n";
		cout << "1.Nhap vao cay nhi phan tim kiem.\n"
			<< "2.Xuat gia tri node cha cua X.\n"
			<< "3.Xuat muc cua cac node tuong ung voi gia tri node trong cay tang dan.\n"
			<< "4.Bac cua cac node co muc L + 1 theo thu tu giam dan gia tri cua node.\n"
			<< "5.Thoat chuong trinh.\n";
		cout << "\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 1 || temp>5) {
			cout << "Khong hop le, nhap lai.\n";
			system("pause");
		}
	} while (temp < 1 || temp>5);
	cin.ignore();
	return temp;
}
bool exec(tree& tree, int mode) {
	::system("cls");
	int x;
	switch (mode)
	{
	case 1:
		do {
			cin >> x;
			if (x > 0) {
				createBinarySearchTree(tree, x);
			}
		} while (x > 0);
		print_RNL(tree);
		break;
	case 2:
		cout << "Nhap khoa X can tim: ";
		cin >> x;
		cout << "Cha cua x= " << x << " la: ";
		cout << search(tree, x) << "\n";
		break;
	case 3:
		level(tree, tree);
		cout << "\n";
		break;
	case 4:
		cout << "Nhap muc L: ";
		cin >> x;
		rank_of_level(tree, tree, x);
		break;
	case 5:
		return false;
	default:
		cout << "Khong hop le, nhap lai.\n";
		break;
	}
	::system("pause");
	return true;
}