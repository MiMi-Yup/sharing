#include <string>
#include <iostream>
using namespace std;

struct Item {
	string word;
	string meaning;
};
struct node {
	Item data;
	node* left;
	node* right;
	node() {
		left = NULL;
		right = NULL;
	}
};
typedef node* tree;
void init(tree& tree) {
	tree = NULL;
}
void standard(string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}
}
node* createNode(string word, string meaning) {
	node* p = new node;
	if (p != NULL) {
		standard(word);
		standard(meaning);
		p->data.word = word;
		p->data.meaning = meaning;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
node* createNode() {
	Item data;
	cout << "Nhap word: "; getline(cin, data.word);
	cout << "Nhap meaning: "; getline(cin, data.meaning);
	standard(data.word);
	standard(data.meaning);
	node* p = new node;
	if (p != NULL) {
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void print_node(node* p) {
	if (p != NULL) {
		cout << "-----------------------------\n";
		cout << "Word: " << p->data.word << "\n";
		cout << "Meaning: " << p->data.meaning << "\n";
	}
}
int createBinarySearchTree(tree& tree, node* p) {
	if (tree != NULL && p != NULL) {

		short compare = tree->data.word.compare(p->data.word);
		if (compare == 0)return 0;
		if (compare == 1)return createBinarySearchTree(tree->left, p);
		else return createBinarySearchTree(tree->right, p);
	}
	else {
		tree = p;
		if (tree == NULL)return -1;
		return 1;
	}
}
node* BinarySearchTree(tree tree, string word) {
	if (tree != NULL) {
		short compare = tree->data.word.compare(word);
		if (compare == 0)return tree;
		if (compare == 1)return BinarySearchTree(tree->left, word);
		return BinarySearchTree(tree->right, word);
	}
	return NULL;
}

node* minValueNode(tree p) {
	node* current = p;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
tree deleteNode(tree root, string word, bool& flag)
{
	if (root == NULL) {
		flag = false;
		return root;
	}
	short compare = root->data.word.compare(word);
	if (compare==1)root->left = deleteNode(root->left, word, flag);
	else if (compare==-1)root->right = deleteNode(root->right, word, flag);
	else {
		node* p;
		if (root->left == NULL) {
			p = root->right;
			delete root;
			root = NULL;
			return p;
		}
		else if (root->right == NULL) {
			p = root->left;
			delete root;
			root = NULL;
			return p;
		}
		p = minValueNode(root->right);
		root->data = p->data;
		root->right = deleteNode(root->right, p->data.word, flag);
		flag = true;
	}
	return root;
}
void print_LNR(tree tree) {
	if (tree != NULL) {
		print_LNR(tree->left);
		print_node(tree);
		print_LNR(tree->right);
	}
}

int menu() {
	int temp;
	do {
		::system("cls");
		cout << "\nVui long chon chuc nang.";
		cout << "\n1. Them 1 Item."
			<< "\n2. Tim kiem."
			<< "\n3. Xoa."
			<< "\n4. In ra."
			<< "\n5. Thoat chuong trinh.";
		cout << "\n\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 1 || temp > 5) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (temp < 1 || temp > 5);
	cin.ignore();
	return temp;
}
bool exec(tree& tree, int mode=menu()) {
	::system("cls");
	string word;
	static node* p;
	bool flag = false;
	switch (mode)
	{
	case 1:
		switch (createBinarySearchTree(tree,p=createNode()))
		{
		case 0:
			cout << "Da co tu " << p->data.word << " trong cay.\n";
			break;
		case -1:
			cout << "Khong the cap phat them bo nho.\n";
			break;
		default:
			break;
		}
		break;
	case 2:
		cout << "Nhap word can tim: ";
		getline(cin, word);
		if ((p = BinarySearchTree(tree, word)) != NULL) {
			cout << "Meaning cua " << word << " la: " << p->data.meaning << "\n";
		}
		else cout << "Khong tim thay " << word << " trong cay.\n";
		break;
	case 3:
		cout << "Nhap word can xoa: ";
		getline(cin, word);
		deleteNode(tree, word, flag);
		if (flag)cout << "Xoa thanh cong " << word << endl;
		else cout << "Xoa that bai.\n";
		break;
	case 4:
		print_LNR(tree);
		break;
	case 5:
		return false;
	default:
		cout << "Khong hop le.\n";
		break;
	}
	::system("pause");
	return true;
}

int main() {
	tree tree;
	init(tree);
	while (exec(tree));
	return(0);
}