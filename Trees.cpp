#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int c;
    char name[10];
    struct node* child[20];
}*root;

class Book{
    public:
    struct node * root;

    Book(){
        root  = NULL;
    }

    void create(){
        root = new node();
        cout<<"Enter the name of book"<<endl;
        cin>>root -> name;
        cout<<"Enter the name of chapters"<<endl;
        cin>>root -> c;

        for(int i=0;i<=root -> c;i++){
            root-> child[i] = new node();
            cout<<"Enter the name of chapter"<<endl;
            cin>>root ->child[i]-> name;
            cout<<"Enter the count of sections"<<endl;
            cin>>root->child[i] -> c;

            for(int j =1;j<=root-> child[i]->c;i++){
                root -> child[i] -> child[j] = new node();
                cout<<"Enter the name of section"<<endl;
                cin>>root -> child[i] -> child[j] -> name;
                 cout<<"Enter the count of sub sections"<<endl;
                 cin>>root ->child[i] -> child[j]-> c;

                 for(int k =1;k<=root -> child[i] -> child[j] -> c;i++){
                    root ->child[i] -> child[j] -> child[k] = new node();

                    cout<<"enter the name of subsection"<<endl;
                    cin>> root -> child[i] -> child[j] -> child[k]-> name;
                 }

            }
        }
    }

    void display(){
        cout<<root-> name<<endl;

        for(int i=1;i<= root -> c;i++){
            cout<< root -> child[i]-> name<<endl;
            for(int j=1;j<= root ->child[i] -> c;j++){
            cout<< root -> child[i]-> child[j] -> name<<endl;
            for(int k=1;k<= root -> c;k++){
            cout<< root -> child[j]->child[j] -> child[k]-> name<<endl;
                 }
               }
            }
         }
};

int main(){
    Book b;
    b.create();
    b.display();
}