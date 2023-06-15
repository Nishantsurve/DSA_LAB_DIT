#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int count;
    char name[20];
    struct node *child[20];
} *root;

class Book
{

public:
    struct node *root;

    Book()
    {
        root = NULL;
    }

    void create()
    {
        root = new node;
        cout << endl
             << "Enter the name of Book :  ";
        cin >> root->name;

        cout << endl
             << "Enter count of Chapters : ";
        cin >> root->count;

        for (int p = 1; p <= root->count; p++)
        {
            root->child[p] = new node;

            cout << endl
                 << "Enter the name of chapter : ";
            cin >> root->child[p]->name;

            cout << endl
                 << "Enter count of Sections : ";
            cin >> root->child[p]->count;

            for (int q = 1; q <= root->child[p]->count; q++)
            {
                root->child[p]->child[q] = new node;

                cout << endl
                     << "Enter the name of Section : ";
                cin >> root->child[p]->child[q]->name;

                cout << endl
                     << "Enter count of Subsections : ";
                cin >> root->child[p]->child[q]->count;

                for (int r = 1; r <= root->child[p]->child[q]->count; r++)
                {
                    root->child[p]->child[q]->child[r] = new node;
                    cout << endl
                         << "Enter the name of Subsection : ";
                    cin >> root->child[p]->child[q]->child[r]->name;
                }
            }
        }
    }

    void display()
    {
        cout << root->name << endl;

        for (int p = 1; p <= root->count; p++)
        {
            cout << "\n       --" << root->child[p]->name;

            for (int q = 1; q <= root->child[p]->count; q++)
            {
                cout << "\n         --" << root->child[p]->child[q]->name;

                for (int r = 1; r <= root->child[p]->child[q]->count; r++)
                {
                    cout << "\n           --" << root->child[p]->child[q]->child[r]->name;
                }
            }
        }
    }
};

int main()
{
    Book b1;
    b1.create();
    b1.display();
}
