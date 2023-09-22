#include "Stack.hpp"

using namespace std;

template <typename T>
Stack<T>::Stack(){
    top_ = NULL;
}

template <typename T>
void Stack<T>::push(T data){
		Node <T>* temp = new Node(data);

		// Check if stack (heap) is full.
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}
		temp->data = data;
		temp->link = top_;
		top_ = temp;
	}

template <typename T>
void Stack<T>::pop() {
    Node <T>* temp;

		if (top_ == NULL) {
			cout << "\nStack Underflow" << endl;
			exit(1);
		}
		else {
			temp = top_;
			top_ = top_->link;
			free(temp);
		}
}

template <typename T>
T Stack<T>::top(){
    if (!isEmpty())
			return top_->data;
		else
			exit(1);
}

template <typename T>
bool Stack<T>::isEmpty(){
    return top_ == NULL;
}


template <typename T>
Stack<T>::~Stack() {
    while (!this->isEmpty()){
            pop();
    }
}

template class Stack<char>;
template class Stack<bool>;
