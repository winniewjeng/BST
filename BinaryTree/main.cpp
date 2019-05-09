#include <cstdlib>
#include <iostream>
#include <fstream>
#include "binarySearchTree.hpp"
//#include "BST"



using namespace std;
//
//void menu(binaryTree<char> tree[],int &toUse);
//void perform(binaryTree<char> &myTree, char selection, int &touse);
//

int main()
{
    node<int> n(4, 3);
//    bstPrivateFxns<int> bst;
//    cout << bst.nodeCount(&n) << endl;
//    cout << bst.totalDataCount(&n) << endl;
    cout <<"hello world"<< endl;
//    cout << max(0,0) << endl;
    bst<int> b;
//    b.insert(30, 15);
   
//    b.insert(70, 25);
    b.insert(50, 25);
    b.insert(10, 25);
    b.insert(70, 25);
//    b.insert(20, 25);
//    b.insert(80, 25);
    
//    b.print();
    

//  binaryTree<char> tree[MAXTREE];
//  int touse=0;
//  menu(tree, touse);
  return 0;
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
