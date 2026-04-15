#include <vector>
template<typename T>
void Tree<T>::insert(T v) {
    insertInternal(v, node);
}

template<typename T>
void Tree<T>::insertInternal(T v, std::unique_ptr<Node<T>>& current)
{
    if (!current) {
        current = std::make_unique<Node<T>>(v);
        size++;
        return;
    }

    if (v < current->value) {
        insertInternal(v, current->left);
    } else if (v > current->value) {
        insertInternal(v, current->right);
    }
}

template<typename T>
void Tree<T>::preOrderInternal(Node<T>* current) const
{ 
    if (!current)
        return;

    std::cout << current->value << std::endl;

    preOrderInternal(current->left.get());
    preOrderInternal(current->right.get());
}

template<typename T>
void Tree<T>::inOrderInternal(Node<T>* current) const
{ 
    if (!current)
        return;

    inOrderInternal(current->left.get());
    std::cout << current->value << std::endl;
    inOrderInternal(current->right.get());
}

template<typename T>
void Tree<T>::postOrderInternal(Node<T>* current) const
{
    if (!current)
        return;

    postOrderInternal(current->left.get());
    postOrderInternal(current->right.get());
    std::cout << current->value << std::endl;
}

template<typename T>
void Tree<T>::preOrder() const
{
    preOrderInternal(node.get());
}

template<typename T>
void Tree<T>::inOrder() const
{
    inOrderInternal(node.get());
}

template<typename T>
void Tree<T>::postOrder() const
{
    postOrderInternal(node.get());
}

template<typename T>
bool Tree<T>::contains(T key) const
{
    Node<T>* current = node.get();

    while(current) {
        if (key == current->value)
            return true;
        if (key > current->value)
            current = current->right.get();
        else
            current = current->left.get();
    }

    return false;
}

template<typename T>
int Tree<T>::getSize(void) const
{
    return size;
}

template<typename T>
void Tree<T>::remove(T key)
{
    removeInternal(node, key);
}

template<typename T>
void Tree<T>::removeInternal(std::unique_ptr<Node<T>>& current, T key)
{
    if (!current)
        return;

    if (key < current->value) {
        removeInternal(current->left, key);
    }
    else if (key > current->value) {
        removeInternal(current->right, key);
    }
    else {
        if (!current->left && !current->right) {
            current.reset();
            size--;
        }
        else if (!current->left) {
            current = std::move(current->right);
            size--;
        }
        else if (!current->right) {
            current = std::move(current->left);
            size--;
        } else {
            Node<T>* succ = current->right.get();
            while (succ->left)
                succ = succ->left.get();
    
            current->value = succ->value;
            removeInternal(current->right, succ->value);
        }
    }
}

template<typename T>
void Tree<T>::printOperatorInternal(std::ostream& os, Node<T>* current) const
{ 
    if (!current)
        return;

    printOperatorInternal(os, current->left.get());
    os << current->value << std::endl;
    printOperatorInternal(os, current->right.get());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& t) {
    t.printOperatorInternal(os, t.node.get());
    return os;
}

template<typename T>
bool Tree<T>::operator>(const Tree<T>& other) const {
    return size > other.size;
}

template<typename T>
bool Tree<T>::operator<(const Tree<T>& other) const {
    return size < other.size;
}

template<typename T>
bool Tree<T>::operator==(const Tree<T>& other) const {
    return size == other.size;
}
