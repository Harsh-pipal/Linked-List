//Author @Harsh_xerus   

#include<bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define rep(i,n) for (int i = 0; i < n; i++)
#define mem0(arr) memset(arr, 0, sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define pb push_back
#define ff first
#define ss second
#define ll long long 
#define pll pair<ll,ll>
#define pss pair<ll,string>
#define vpss vector<pss>
#define vll vector<ll>
#define vpll vector<pll>
#define INF 1e18
#define nl '\n'
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll maxn = 1e6 + 2;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//------------------------------Debugger-----------------------------------//

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//--------------------------Helper_functions-------------------------------//

//-------------------------------GCD---------------------------------------//

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}

//-------------------------------LCM---------------------------------------//

ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}

//----------------------------Factorial------------------------------------//

ll fact(ll x){if(x==0)return 1;return (x*fact(x-1))%mod;}

//-----------------------------Bin_Expo------------------------------------//

ll binpow(ll a,ll b) {
    //a%=mod;                 //here too
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);  //add mod if needed
        a = (a * a);          //add mod if needed
        b >>= 1;
    }
    return res;
}

//-------------------------Sum/Count of digits----------------------------//

ll sd(ll x){ll temp=0;while(x>0){temp+=x%10;x/=10;}return temp;}
ll cd(ll x){ll temp=0;while(x>0){temp++;x/=10;}return temp;}

//-------------------------------START------------------------------------//

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    head = n;
}

bool searchTheKey(node* head, int key){
    node* temp = head;
    while(temp->next != NULL){
        if(temp->data == key){
            //cout<<1<<nl;
            return true;
        }
        temp= temp->next;
    }
    //cout<<0<<nl;
    return false;
}

void deleteHead(node* &head){
    node * tobedeleted = head;
    head = head->next;
    delete tobedeleted;
}

void deleteNode(node* head, int val){

    if(head==NULL)       //empty linked list, so just return
        return;

    if(head->next == NULL){      // only one element so call delete head func
        deleteHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node * tobedeleted = temp->next;
    temp->next = temp->next->next;

    delete tobedeleted;
}

void display(node *head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp= temp->next;
    }
    cout<<"NULL";
    cout<<nl;
}

node* reverselist(node *head){

    //making three pointers prev,curr,next

    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    while(curr!=NULL){
        nextptr=curr->next;
        curr->next = prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;

}

node* reverselistRecursive(node *head){

    if(head==NULL or head->next==NULL){
        return head;
    }
    node* newhead = reverselistRecursive(head->next);
    head->next->next=head;
    head->next = NULL; 

    return newhead;
}

void solve(){

    //linked list is a data structure which consists of two parts
    // node = data | next
    //data stores the value and next points to next pointer

    //making a linked list

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,5);
    display(head);
    deleteNode(head,3);
    deleteHead(head);
    display(head);
    searchTheKey(head,3);
    node* newhead = reverselistRecursive(head);
    display(newhead);

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1, i = 1;
    //cin >> t;
    cout << std::setprecision(15);
    //presolve();
    clock_t start, end;
    start = clock();
    while (t--)
    {
        //cout << "Case #" << i << ": ";   //only during google contest
        //i++;                             //only during google contest

        solve();
    }
    end = clock();
    double Time = double(end - start) / double(CLOCKS_PER_SEC);
    debug(Time)
}
 
