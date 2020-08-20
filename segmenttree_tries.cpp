#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#pragma GCC optimize ("-O3")
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define tolower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define toupper(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define ll long long int
#define case(i) cout<<"Case #"<<i<<": ";
#define pii pair <ll , ll >
#define pb push_back
#define PRECISION 10
const ll inf = 1e16;
const int MAXN = 300001;
const int MAXK = 22;
ll mod = 1e9 + 7;
const ll MOD1 = 998244353;
const ll DIGITSIZE = 19;
int x4[] = {1, -1, 0, 0};
int y4[] = {0, 0, 1, -1};
int n;
int arr[MAXN];
struct node
{
    node *child[2];
};
node* getnode(){
    node* temp=new node;
    temp->child[0]=NULL;
    temp->child[1]=NULL;
    return temp;
}
void merge(node* &root,node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)return;
    root=new node();
    if(root1==NULL){root=root2;return;}
    if(root2==NULL){root=root1;return;}
    merge(root->child[0],root1->child[0],root2->child[0]);
    merge(root->child[1],root1->child[1],root2->child[1]);
}
void insert(node* root,int x){
    node* curr = root;
    for(int i=20; i>=0; i--){
        int b = (x>>i)&1;
        if(b==0){
            if(!curr->child[0]){
                curr->child[0] = new node();
            }
            curr = curr->child[0];
        }else{
            if(!curr->child[1]){
                curr->child[1] = new node();
            }
            curr = curr->child[1];
        }
    }
}
node* segtree[4 * MAXN];
void build(int curr, int s, int e) {
    if (s == e) {
        // node* a=getnode();
        segtree[curr]=getnode();
        insert(segtree[curr],arr[s]);
        return ;
    }
    int mid = (s + e) / 2;
    build(2 * curr, s, mid);
    build(2 * curr + 1, mid + 1, e);
    merge(segtree[curr],segtree[2*curr],segtree[2*curr+1]);
    return ;
}
int findmax(node* root,int val){
    int maxVal = 0;
    node* curr = root;
    for(int i=20; i>=0; i--){
        int b = (val>>i)&1;
        if(b==0){
            if(curr->child[1]){
                maxVal += (1<<i);
                curr=curr->child[1];
            }else{
                curr=curr->child[0];
            }
        }else{
            if(curr->child[0]){
                maxVal += (1<<i);
                curr=curr->child[0];
            }else{
                curr=curr->child[1];
            }
        }
    }
    return maxVal;
}
ll query(int curr, int qs, int qe, int s, int e, int val) {
    if (qe < s || qs > e) 
        return 0;  // base condition 
    if (qs <= s && e <= qe) {
        return findmax(segtree[curr],val); // current segment lies completly inside range segment
    }
    else {
        int mid = (s + e) / 2;
        return max(query(2*curr,qs,qe,s,mid,val),query(2*curr+1,qs,qe,mid+1,e,val)); // return result from both left and right ;
    }
}

void getac(int T){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1, 1, n);
    int q;
    cin>>q;
    int ii=0;
    
}
int  main()
{

    fastio;


    int t = 1;
   // cin >> t;
    int t_t = 1;
    while (t--) {

        getac(t_t);
        t_t++;
    }
    return 0;
}