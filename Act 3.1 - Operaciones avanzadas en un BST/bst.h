/*
Ricardo Andres Caceres Villibord
A01706972
Archivo .h para la actividad Formativa 3.1
*/


#include <string>
#include <sstream>
#include <iostream>


template <class T> class BST;

template <class T>
class Node {
	private:
		T value;
		Node *left, *right;

		Node<T>* succesor();

	public:
		Node(T);
		Node(T, Node<T>*, Node<T>*);
		void add(T);
		bool find(T);
		void remove(T);
		void removeChilds();

        void preorder(std::stringstream&) const;
        void inorder(std::stringstream&) const;
        void postorder(std::stringstream&) const;

        int height() const;
        bool ancestors(T, std::stringstream&) const;
        int whatlevelamI(T);

		void showlevel(std::stringstream&, int) const;
		void levelbylevel(std::stringstream&) const;

		friend class BST<T>;
};

template <class T>
Node<T>::Node(T val): value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri): value(val), left(le), right(ri) {}


template <class T>
void Node<T>::add(T val){
    //Si es menor vamos a agregar a la izquierda
	if (val < value){
		if (left != NULL){
			left->add(val);
		}
		else {
			left = new Node<T>(val);
		}
	} //Pero si es mayor vamos a agregar a la derecha
	else {
		if (right != NULL){
			right->add(val);
		}
		else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val){
    //Si en el que estamos es el valor que se busca
	if (val == value){
		return true;
	}
	else if (val < value){ //Si el val es menor al que buscamos, llamos otra vez find pero en el left
		return (left != 0 && left->find(val));
	}
	else if (val > value){ //Si el val es mayor al que buscamos, llamamos otra vez find peron en el right 
		return (right != 0 && right->find(val));
	}
}

template <class T>
Node<T>* Node<T>::succesor(){
	Node<T> *l, *r;

	l = left;
	r = right;

	if (left == NULL) {
		if (right != NULL) {
			right = NULL;
		}
		return r;
	}
	if (left->right == NULL) {
		left = left->left;
		l->left = NULL;
		return l;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != NULL) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = NULL;
	return child;
}


template <class T>
void Node<T>::remove(T val){
    Node<T> *succ, *old;

    if(val < value){
        if(left != NULL){
            if(left->value == val){
                old = left;
                if(old->left != NULL && old->right != NULL){ //Si tiene dos hijos
                    succ = left->succesor();
                    if(succ != NULL){
                        succ->left = old->left;
                        succ->right = old->right;
                    }
                    left = succ;
                } else if(old->right != NULL){ // Si solo hay hijo der
                    left = old->right; //Reapunta la flechita del left
                } else if(old->left != NULL){ //Si solo hay hijo izq
                    left = old->left; //Reapunta la flechita del left
                } else { //hoja
                    left = NULL;
                }
                delete old;
            } else{
                left->remove(val);
            }
        }
    } else if(val > value){
        if(right != NULL){
            if(right->value == val){
                old = right;
                if(old->left != NULL && old->right != NULL){ //Si tiene dos hijos
                    succ = right->succesor();
                    if(succ != NULL){
                        succ->left = old->left;
                        succ->right = old->right;
                    }
                    right = succ;
                } else if(old->right != NULL){ //Si solo hay hijo der
                    right = old->right; //Reapunta la flechita de right
                } else if(old->left != NULL){ //Si solo hay hijo izq
                    right = old->left; //Reapunta la flechita de right
                } else{ //hoja
                    right = NULL;
                }
                delete old;
            } else{
                right->remove(val);
            }
        }
    }


}

template <class T>
void Node<T>::removeChilds(){
	if (left != NULL) {
		left->removeChilds();
		delete left;
		left = NULL;
	}
	if (right != NULL) {
		right->removeChilds();
		delete right;
		right = NULL;
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const{
	if (left != NULL) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != NULL) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const{

	aux << value;
	if (left != NULL) {
		aux<<" ";
		left->preorder(aux);
	}
	if (right != NULL) {
		aux<<" ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const{

	if (left != NULL) {
		left->postorder(aux);
	}
	if (right != NULL) {
		right->postorder(aux);
	}
	if (aux.tellp() != 1) {
			aux<<" ";
	}
	aux<<value;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream &aux) const {

    aux << value;
    if (left != NULL) {
    aux<<" ";
        left->levelbylevel(aux);
    }
    if (right != NULL) {
    aux<<" ";
        right->levelbylevel(aux);
    }
}

template <class T>
int Node<T>::height() const {
	int izq = 0;
	int der = 0;

	if (left != 0){
		izq = left->height() + 1;
	}
	if (right != 0) {
		der = right->height() +1;
	}
	if (izq == 0 && der == 0){
		return 1;
	}
	return ( der > izq) ? der : izq;
}

template <class T>
bool Node<T>::ancestors(T val, std::stringstream &aux) const{

	if(val == value){
	  return true;
	} else if(val < value){
		if(aux.tellp() != 1){
			aux<<" ";
		}
		aux << value;
		return (left != NULL && left->ancestors(val,aux));
	} else if(val > value){
		if(aux.tellp() != 1){
			aux << " ";
		}
		aux << value;
		return (right != NULL && right->ancestors(val,aux));
	}
	return false;
}

template <class T>
int Node<T>::whatlevelamI(T val){

	if (val == value){
		return 1;
	} else if (val < value){
		if(left != NULL){
            return left->whatlevelamI(val) + 1;
        }
	} else if (val > value) {
		if (right != NULL){
            return right->whatlevelamI(val) + 1;
        }
	}
	return -1;
}


template <class T>
class BST{
	private:
		Node<T> *root;

	public:
		BST();
		~BST();
		bool empty() const;
		void add(T);
		bool find(T) const;
		void remove(T);
		void removeAll();

        std::string inorder() const;
		std::string preorder() const;
		std::string postorder() const;
		std::string levelbylevel() const;

        int height() const;
        std::string ancestors(T) const;
		int whatlevelamI(T);
		std::string visit();
};


template <class T>
BST<T>::BST(): root(0) {}

template <class T>
BST<T>::~BST(){
	removeAll();
}

template <class T>
bool BST<T>::empty() const{
	return (root == 0);
}

template<class T>
void BST<T>::add(T val){
	if (root != NULL){
		if (!root->find(val)){
			root->add(val);
		}
	}
	else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const{
	if (root != NULL){
		return root->find(val);
	}
	else {
		return false;
	}
}

template <class T>
void BST<T>::remove(T val){
	if (root != NULL) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != NULL) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		}
		else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll(){
	if (root != NULL){
		root->removeChilds();
	}
	delete root;
	root = NULL;
}

template <class T>
int BST<T>::whatlevelamI(T val){

	if (root != NULL) {
	 	int num = root->whatlevelamI(val);
		if(num < 0){
            return -1;
        } 
		return num;
	} else{
		return -1;
	}
}

template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;

	aux<<"[";
	if (!empty()) {
		if(!root->ancestors(val, aux)){
            return "[]";
        }
	}
	aux<<"]";

	return aux.str();
}

template <class T>
int BST<T>::height() const{
	return root->height();
}

template <class T>
std::string BST<T>::visit(){
	std::stringstream aux;
    
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelbylevel();
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const{
	std::stringstream aux;

	aux<<"[";
	if (!empty()){
		root->preorder(aux);
	}
	aux<<"]";

	return aux.str();
}


template <class T>
std::string BST<T>::inorder() const{
	std::stringstream aux;

	aux<<"[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux<<"]";

	return aux.str();
}


template <class T>
std::string BST<T>::postorder() const{
	std::stringstream aux;

	aux<<"[";
	if (!empty()){
		root->postorder(aux);
	}
	aux<<"]";

	return aux.str();
}


template <class T>
std::string BST<T>::levelbylevel() const{
	std::stringstream aux;

	aux<<"[";
	if (!empty()){
		root->levelbylevel(aux);
	}
	aux<<"]";

	return aux.str();
}








