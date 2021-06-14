#include <iostream>
#include <string>
using namespace std;

struct node {
	int MSSV;
	string lastname;
	string firstname;
	float score;
	node* left;
	node* right;
	node() {
		MSSV = NULL;
		score = NULL;
		left = NULL;
		right = NULL;
	}
};
typedef node* tree;
void init(tree& tree) {
	tree = NULL;
}
node* createNode(int MSSV, string lastname, string firstname, float score) {
	node* p = new node;
	if (p != NULL) {
		p->MSSV = MSSV;
		p->lastname = lastname;
		p->firstname = firstname;
		if (score < 0.0 || score > 10.0) {
			delete p;
			p = NULL;
			return p;
		}
		p->score = score;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
node* createNode() {
	int MSSV;
	string lastname;
	string firstname;
	float score;
	cout << "\tNhap MSSV: ";
	cin >> MSSV;
	cin.ignore();
	cout << "\tNhap ho sinh vien: "; getline(cin, lastname);
	cout << "\tNhap ten sinh vien: "; getline(cin, firstname);
	do {
		cout << "\tNhap diem trung binh: ";
		cin >> score;
		if (score < 0.0 || score > 10.0) cout << "Diem khong hop le, nhap lai.";
	} while (score < 0.0 || score > 10.0);
	return createNode(MSSV, lastname, firstname, score);
}
void print_node(node* node) {
	cout << "-----------------------------\n";
	cout << "\tMSSV: " << node->MSSV << "\n";
	cout << "\tHo va ten: " << node->lastname << " " << node->firstname << "\n";
	cout << "\tDiem trung binh: " << node->score << "\n";
}
int createBinarySearchTree(tree& tree, node* node) {
	if (tree != NULL) {
		if (node == NULL)return -1;
		if (tree->MSSV == node->MSSV)return 0;
		if (tree->MSSV > node->MSSV)return createBinarySearchTree(tree->left, node);
		else return createBinarySearchTree(tree->right, node);
	}
	else {
		tree = node;
		return 1;
	}
}
node* BinarySearchTree(tree tree, int MSSV) {
	if (tree != NULL) {
		if (tree->MSSV == MSSV)return tree;
		if (tree->MSSV > MSSV)return BinarySearchTree(tree->left, MSSV);
		return BinarySearchTree(tree->right, MSSV);
	}
	return NULL;
}

node* minValueNode(tree p) {
	node* current = p;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}
void copy(node* source, node* target) {
	if (source!=NULL && target != NULL) {
		target->firstname = source->firstname;
		target->lastname = source->lastname;
		target->MSSV = source->MSSV;
		target->score = source->score;
	}
}
tree deleteNode(tree& root, node*q)
{
	if (root == NULL) {
		return root;
	}
	if (q->MSSV < root->MSSV)root->left = deleteNode(root->left, q);
	else if (q->MSSV > root->MSSV)root->right = deleteNode(root->right, q);
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
		copy(p, root);
		root->right = deleteNode(root->right, p);
	}
	return root;
}
void filter(tree& root, float score, tree& sub) {
	if (root != NULL && sub != NULL) {
		filter(root, score, sub->left);
		filter(root, score, sub->right);
		if (sub->score < score) {
			deleteNode(root, sub);
		}

	}
}

void print_NLR(tree tree) {
	if (tree != NULL) {
		print_node(tree);
		print_NLR(tree->left);
		print_NLR(tree->right);
	}
}
void print_NRL(tree tree) {
	if (tree != NULL) {
		print_node(tree);
		print_NRL(tree->right);
		print_NRL(tree->left);
	}
}
void print_LRN(tree tree) {
	if (tree != NULL) {
		print_LRN(tree->left);
		print_LRN(tree->right);
		print_node(tree);
	}
}
void print_RLN(tree tree) {
	if (tree != NULL) {
		print_RLN(tree->right);
		print_RLN(tree->left);
		print_node(tree);
	}
}

int menu() {
	int temp;
	do {
		::system("cls");
		cout << "\nVui long chon chuc nang.";
		cout << "\n1. Nhap vao cay nhi phan tim kiem."
			<< "\n2. Hien thi danh sach."
			<< "\n3. Loc bo sinh vien co DTB < 5."
			<< "\n4. Thoat chuong trinh.";
		cout << "\n\nLua chon cua ban: ";
		cin >> temp;
		if (temp < 1 || temp > 4) {
			cout << "Khong hop le, nhap lai.\n";
			::system("pause");
		}
	} while (temp < 1 || temp > 4);
	return temp;
}
bool exec(tree& tree, int mode = menu()) {
	::system("cls");
	int x;
	node* p = NULL;
	switch (mode)
	{
	case 1:
		cout << "Nhap so luong sinh vien muon dua vao cay: ";
		cin >> x;
		for (int i = 0; i < x; i++) {
			system("cls");
			cout << "Sinh vien thu " << i << ": \n";
			switch (createBinarySearchTree(tree, p = createNode()))
			{
			case 0:
				cout << "Da co sinh vien " << p->MSSV << " trong cay.\n";
				break;
			case -1:
				cout << "Khong the cap phat them bo nho.\n";
			default:
				break;
			}
			system("pause");
		}
		break;
	case 2:
		cout << "NLR: "; print_NLR(tree); cout << endl;
		cout << "NRL: "; print_NRL(tree); cout << endl;
		break;
	case 3:
		filter(tree, 5.0, tree);
		cout << "LRN: "; print_LRN(tree); cout << endl;
		cout << "RLN: "; print_RLN(tree); cout << endl;
		break;
	case 4:
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

/*test case
1
16 5 4 9 3 6 12 1 8 10 13 2 7 11 14 16 15
2 4
4
6
14
3 9
15 8
*/

