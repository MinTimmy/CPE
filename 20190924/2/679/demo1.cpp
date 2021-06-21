#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int index;
    bool value;
    Node* left;
    Node* right;
};

int count1 = 0;

Node* makeTree(Node* r, int d)
{
    if(d >= 0){
        r->left = new Node{0,false,NULL,NULL};
        r->right = new Node{0,false,NULL,NULL};
        if(d == 0){
            cout << count1 << '\n';
            r->index = count1;
            count1++;
        }
        r->left = makeTree(r->left, d-1); 
        r->right = makeTree(r->right, d-1);
       
    }
    return r;
}

int find1(Node* r)
{
    int a;
    if(r->value){
        r->value = false;
        if(r->right == NULL){
            cout << "r->index = " << r->index << '\n';
            return r->index;
        }
        a = find1(r->right);
    }
    else{
        r->value = true;
        if(r->left == NULL){
            cout << "r->index = " << r->index << '\n';
            return r->index;
        }
        a = find1(r->left);
    }
    cout << "a = " << a << '\n';
    return a;
}

int main()
{
    freopen("input2","r",stdin);
    freopen("output1","w",stdout);
    int caseN = 0;
    cin >> caseN;

    while(caseN--){
        int d,i;

        cin >> d >> i;

        Node* root = new Node{0,false,NULL,NULL};
        count1 = pow(2,d) - pow(2,d-1);
        makeTree(root,d);

        cout << find1(root) << "\n--------------------------------------\n";
        count1 = 0;
    }
    cin >> caseN;
}