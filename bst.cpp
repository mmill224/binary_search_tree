#include <iostream>


class Bstree {
public:
	Bstree();
	Bstree(int);
	~Bstree();

	void add(int);
	void remove(int);
	Bstree* search(int);
	Bstree* returnSearch(int);
	void printTree();
	void printTreeLTG();
	void printTreeGTL();
	int getPayload() { if (this == nullptr) return 0; return payload; }

private:
	int payload;
	Bstree* left;
	Bstree* right;

};

Bstree::Bstree() {
	left = nullptr;
	right = nullptr;
}
Bstree::Bstree(int n) {
	left = nullptr;
	right = nullptr;
	payload = n;
}

Bstree::~Bstree() {
	delete left;
	delete right;
}

void Bstree::remove(int n) {
	if (payload == n) {
		if (left != nullptr || right != nullptr) {

		}
		delete this;
	}
}

void Bstree::add(int n){
	if (n <= payload) {
		if (left == nullptr)
			left = new Bstree(n);
		else left->add(n);
	}
	else if (n > payload){
		if (right == nullptr)
			right = new Bstree(n);
		else right->add(n);
	}
}

void Bstree::printTree() {
	std::cout << payload << ", ";
	if (left == nullptr && right == nullptr) return;
	if (left != nullptr) left->printTree();
	if (right != nullptr) right->printTree();
}



void Bstree::printTreeLTG() {
	if (left != nullptr) left->printTreeLTG();
	std::cout << payload << ", ";
	if (right != nullptr) right->printTreeLTG();
}

void Bstree::printTreeGTL() {
	if (right != nullptr) right->printTreeGTL();
	std::cout << payload << ", ";
	if (left != nullptr) left->printTreeGTL();
	
}

Bstree* Bstree::search(int n) {
	std::cout << "searching... ";
	if (payload == n) { std::cout << n << " was found!" << std::endl; return this; };
	if (n < payload) {
		if (left != nullptr)
			return left->search(n);
	}
	else if (right != nullptr)
		return right->search(n);
	return nullptr;
}

Bstree* Bstree::returnSearch(int n) {
	Bstree* result = search(n);
	if (result == nullptr) {
		std::cout << n << " was not found..." << std::endl;
	}
	return result;
}

int main() {

	Bstree* tree = new Bstree(50); std::cout << "50, ";
	tree->add(10); std::cout << "10, ";
	tree->add(5); std::cout << "5, ";
	tree->add(7); std::cout << "7, ";
	tree->add(3); std::cout << "3, ";
	tree->add(10); std::cout << "10, ";
	tree->add(5); std::cout << "5, ";
	tree->add(7); std::cout << "7, ";
	tree->add(3); std::cout << "3, ";
	tree->add(75); std::cout << "75, ";
	tree->add(55); std::cout << "55, ";
	tree->add(88); std::cout << "88, ";
	tree->add(11); std::cout << "11, ";
	tree->add(51); std::cout << "51, ";
	tree->add(72); std::cout << "72, ";
	tree->add(33); std::cout << "33, ";
	tree->add(15); std::cout << "15, ";
	tree->add(57); std::cout << "57, ";
	tree->add(78); std::cout << "78, ";
	tree->add(39); std::cout << "39, ";
	tree->add(79); std::cout << "79, ";
	tree->add(69); std::cout << "69, ";
	tree->add(24); std::cout << "24, \n";
	tree->printTreeLTG();
	int n = 1;

	while (n != 0) {
		std::cout << std::endl << "enter a number to find: ";
		std::cin >> n;
		tree->returnSearch(n);
		//std::cout << "enter 0 to continue: ";
		//std::cin >> end;
	}
}