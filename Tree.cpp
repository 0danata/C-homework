
#include <iostream>
using namespace std;



struct Node                         
{
	int data;                          
	Node* l, * r;                      
};

Node* Balanced_tree(int val)
{
	Node* newBtree = new Node;
	int x;
	int L = NULL;
	int R;
	if (val == 0)
	{
		return newBtree;
	}
	else
	{
		L = val / 2;
		R = val - L - 1;
		
		newBtree->data = val;
		newBtree->l = Balanced_tree(L);
		newBtree->r = Balanced_tree(R);
	}
	return newBtree;
}

void Tree_push(Node *&tree, int x)
{

	if (tree == nullptr)
	{
		tree = new Node;
		tree->data = x;
		tree->l = nullptr;
		tree->r = nullptr;
		cout << "New tree added" << endl;
		return;
	}
	else
	{
		if (x < tree->data)
		{
			Tree_push(tree->l, x);
		}
		else 
		{
			Tree_push(tree->r, x);
		}
	}
}
//void Print_tree(Node* tree)
//{
//	if (!tree)
//		return;		//Пока не встретится пустое звено
//	
//		if (tree->l)
//		{
//			cout << tree->data << "Left val" << '\t';
//			Print_tree(tree->l);
//		}           
//		else 
//		{
//			cout << tree->data << "Right val" << '\t';
//			Print_tree(tree->r);
//		}
//}
int tabs = 0;
void print(Node* tree)
{
	
	if (!tree) return;
	tabs++; //Иначе увеличим счетчик рекурсивно вызванных процедур
	//Который будет считать нам отступы для красивого вывода

	print(tree->l); //Выведем ветку и ее подветки слева

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << tree->data << endl; //Данные этой ветки


	print(tree->r);

	tabs--; //После уменьшим кол-во отступов
	return;
}

void Del_tree(Node* tree)
{
	if (!tree)
		return;
	Del_tree(tree->l);
	Del_tree(tree->r);
	delete tree;
	return;
}

int main()
{

	Node* tree = nullptr;
	int num = 10;
	tree = (Balanced_tree(10000));
	
	for (size_t i = 0; i < 49; i++)
	{
		Tree_push(tree,10000);
	}
	print(tree);
	Del_tree(tree);
}