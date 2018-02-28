#include<bits/stdc++.h>
using namespace std;

int arr[1000009];

struct node{
	int s,e,val;
	struct node *left, *right, *next;
};

map<int,int> rep;
map<int,int> pos;

struct node* newnode(){
	struct node* root = (struct node*)malloc(sizeof(struct node));
	root->left = root->right = root->next = NULL;
	root->s = root->e = root->val = 0;
	return root;
}

struct node* build(int s,int e){
	root = newnode();
	root->s = s;
	root->e = e;
	if(s==e){
		if(next[arr[s]]!=-1){root->val = 0;}
		else{root->val = 1;}
		return root;
	}

	int m = (s+e)/2;
	root->left = build(s,m);
	root->right = build(m+1,e);

	root->val = root->left->val + root->right->val;
	return root;
}

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){cin>>arr[i];}

	for(int i=0;i<n;i++){
		if(pos.find(arr[i]) == pos.end()){
			pos[arr[i]] = i;
			rep[i] = -1;
		}else{
			rep[i] = pos[arr[i]];
			pos[arr[i]] = i;
		}
	}

	for(int i=0;i<n;i++){
		cout<<rep[i]<<" ";
	}cout<<endl;

//	struct node *root;
//	root = (struct node*)malloc(sizeof(struct node));

//	root = build(0,n-1);

//	for(int i=1;i<n;i++){

//	}
}