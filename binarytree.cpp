#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class node
{
public:
    int key;
    node *left;
    node* right;
};

class tree{
public:
node* root;

node* createtree(int v){
    root  =  new node();
    root ->key = v;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}
void insertnode(int v,node* root){
    node* r = new node();
    r -> key = v;
    if(root->key > v){
        if(root -> left == NULL){
            root -> left = r;
        }
        else{
            insertnode(v , root -> left);
        }
    }

    else if(root->key < v){
        if(root -> right == NULL){
            root -> right = r;
        }
        else{
            insertnode(v , root -> right);
        }
    }
    else{
        cout<<"No duplicates are allowed"<<endl;
    }
}

void display(node* root){

if(root!=NULL){
    display(root ->left);
    cout<<root -> key<<" ";
    display(root -> right);
}

}

void displaymin(node* root){
    while(root!=NULL){
        root = root -> left;
    }
    cout<<"minimum data value present in tree"<<root ->key;
}

node* swapnode(node* root){
    node* temp;

    if(root == NULL){
        return;
    }
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

    swapnode(root -> left);
    swapnode(root -> right);
}

};

int main()
{
    int choice, flag=0;
    int key;
    tree t1;
    node* root;
    do{
        cout<<"1.enter the number"<<endl;
        cout<<"2.display tree"<<endl;
        cout<<"3. display min"<<endl;
        cout<<"4.swapnode"<<endl;
        cout<<"5.exit"<<endl;

        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<endl;
            cout<<"enter the number"<<endl;
            cin>>key;
            if(flag==0){
                root = t1.createtree(key);
                flag=1;
            }
            else{
                t1.insertnode(key, root);
            }
            break;

            case 2:
              t1.display(root);
              break;
            
            case 3:
            t1.displaymin(root);
            break;

            csae 4:
            t1.swapnode(root);
            cout<<"after traversal"<<endl;
            t1.display(root);
            break;

            default:
              break;
        }
    }while(choice!=5);
}
