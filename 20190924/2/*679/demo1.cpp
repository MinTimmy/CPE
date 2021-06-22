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
    
    if(d > 0){      
        if(d == 1){
            // cout << "count1 = " << count1 << '\n';
            r->index = count1;
            
            // r->left = NULL;
            // r->right = NULL;
            count1++;
            
        }
        else{
            // r->index = -1;
            r->left = new Node{0,false,NULL,NULL};
            r->right = new Node{0,false,NULL,NULL};
            r->left = makeTree(r->left, d-1); 
            r->right = makeTree(r->right, d-1);
        }
       
    }
    return r;
}

int find1(Node* r)
{
    int a;
    if(r->value){
        r->value = false;
        if(r->right == NULL){
            // cout << "r->index = " << r->index << '\n';
            return r->index;
        }
        // cout << "right" << " r->index = " << r->index<< "\n";
        a = find1(r->right);
    }
    else{
        r->value = true;
        if(r->left == NULL){
            // cout << "r->index = " << r->index << '\n';
            return r->index;
        }
        // cout << "left" << " r->index = " << r->index << "\n";
        a = find1(r->left);
    }
    // cout << "a = " << a << '\n';
    return a;
}

int main()
{
    freopen("input1","r",stdin);
    freopen("output1","w",stdout);
    int caseN = 0;
    cin >> caseN;

    while(caseN--){
        int d,i;

        cin >> d >> i;

        Node* root = new Node{0,false,NULL,NULL};
        count1 = pow(2,d) - pow(2,d-1);
        root = makeTree(root,d);
        // cout << "root->index = " << root->left->left->left->index << "\n";

        int ans;
        while(i--){
            ans = find1(root);
        }
        cout << ans << "\n";
        count1 = 0;
        delete root;
    }
    cin >> caseN;
}