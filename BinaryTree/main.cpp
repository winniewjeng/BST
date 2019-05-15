#include <cstdlib>
#include <iostream>
#include <fstream>
#include "binarySearchTree.hpp"

using namespace std;

void testInsert(bst<int>& b);
void testSearch(bst<int>& b);
void testRemove(bst<int>& b);

int main(int argc, char const* argv[]) {
    bst<int> b;
    
    testInsert(b);
    testRemove(b);
//    testInsert(b);
    b.insert(3,1);
    b.print();

    return 0;
}

void testInsert(bst<int>& b) {
    
//    for (int i = 10; i > 0; --i)
//        b.insert(i, i);

    int rightZig[] = {41,20,65,11,32,50,91,29,33,72,99,30, 45, 55};
    for (int i = 0; i < 14; ++i)
        b.insert(rightZig[i],1);
    b.print();
}

void testSearch(bst<int>& b) {
    
    node<int>* n1 = b.search(5);
    if(!n1)
        cout << "wth\n";
    else {
        cout << n1->getData() << endl;
    }
    node<int>* n2 = b.search(5);
    if(!n2)
        cout << "wthh\n";
    else {
        cout << n2->getData() << endl;
    }
    if (n1==n2) {
        cout << "yeh\n";
    }
    
    node<int>* b1;
    b1 = b.search(4);
    b1->getData();
    
    
};

void testRemove(bst<int>& b) {
    b.remove(33);
    b.remove(30);
    b.remove(41);
    b.remove(65);
    b.print();
    
}

//
//void perform(binaryTree<char> tree[], char selection, int &touse)
//{
//   char value;
//   int order;
//   char name[30];
//   switch(toupper(selection))
//   {
//
//     case '+' :
//     case 'E' : cout<<"What value do you want to put into the tree? ";
//                cin>> value;
//                tree[touse].insert(value);
//                break;
//
//     case '-' :
//     case 'D' : cout<<"What value do you want to see if it is in the tree? ";
//                cin>> value;
//                if(tree[touse].remove(value))
//                   cout<<value<<" removed successfully"<<endl;
//                else
//                   cout<<"Item not in tree -- therefore it was not removed."<<endl;
//                break;
//
//     case 'B' : if(tree[touse].balanced())
//                    cout<<"Your tree is balanced!"<<endl;
//                else
//                {
//                   tree[touse].rebalance();
//                   cout<<"Your tree is now balanced!"<<endl;
//                }
//                break;
//
//     case 'P' : cout<<tree[touse]<<endl;
//                break;
//
//     case 'F' : cout<<"What value do you want to see if it is in the tree? ";
//                cin>> value;
//                if(tree[touse].find(value))
//                     cout<<"The tree has this value in it"<<endl;
//                else
//                    cout<<"The tree does not have this value in it"<<endl;
//                break;
//
//
//     case 'C' : cout<<"There are "<<tree[touse].totalDataCount()<<" items in the tree "<<endl;
//                break;
//
//     case 'N' : cout<<"There were "<<tree[touse].totalDataCount()<<" items in the tree you just disposed"<<endl;
//                tree[touse].clear();
//                break;
//
//     case 'S' : do
//                {
//                   cout<<"Enter 1 for a PREORDER, 2 for INORDER and 3 for POSTORDER ";
//                   cin>>order;
//                }while(order<1 || order > 3);
//                switch(order)
//                {
//                    case 1: tree[touse].setTraversal(PRE_ORDER);
//                            break;
//                    case 2: tree[touse].setTraversal(IN_ORDER);
//                            break;
//                    case 3: tree[touse].setTraversal(POST_ORDER);
//                            break;
//                }
//                break;
//
//     case 'T' : do
//                {
//                   cout<<"Which tree do you want to use: ";
//                   cin>>order;
//                }while(order < 0 || order > MAXTREE);
//                break;
//
//
//     case 'W' : {
//                  ofstream out;
//                  cout<<"What is the name of the file you want to write to: ";
//                  cin>>name;
//                  out.open(name);
//                  out<<tree[touse];
//                  out.close();
//                  break;
//                }
//
//     case 'R' : {
//                  ifstream in;
//                  cout<<"What is the name of the file you want to read from: ";
//                  cin>>name;
//                  in.open(name);
//                  in>>tree[touse];
//                  in.close();
//                  break;
//                }
//
//     case 'Q' : cout<<"Goodbye"<<endl;
//   }
//}
//
//
//void menu(binaryTree<char> tree[],int &toUse)
//{
//  char selection;
//  do
//  {
//     cout<<endl;
//     cout<<"Menu Selections for tree operations"<<endl
//         <<" E. Enter data"<<endl
//         <<" D. Delete data"<<endl
//         <<" B. Balanced"<<endl
//         <<" S. Select print order"<<endl
//         <<" P. Print the tree"<<endl
//         <<" F. Find if an item is in the tree"<<endl
//         <<" T. Select tree to use"<<endl
//         <<" R. Read from a file"<<endl
//         <<" W. Write to a file"<<endl
//         <<" C. Count how many items are in the tree"<<endl
//         <<" N. Empty the tree"<<endl
//         <<" Q. Quit"<<endl
//         <<"What is your selection: ";
//     cin>>selection;
//     perform(tree, selection, toUse);
//  }while(toupper(selection) != 'Q');
//};
//
