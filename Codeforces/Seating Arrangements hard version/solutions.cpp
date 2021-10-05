#include <bits/stdc++.h>
using namespace std;
#define in(x) int x; cin >> x;
#define sin(s) string s; cin >> s;
#define ll long long
#define lin(x) ll x; cin >> x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i, n) for (int i = 0; i < n; i++)
#define pe(i, a, b) for (ll i = a; i <= b; i++)
#define rre(i, n) for (int i = n - 1; i > -1; i--)
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define endl "\n"
//#define pi acos(-1)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define ninf -INT_MAX
#define inf 100000000000000000
#define mod 998244353
#define x first
#define y second

// BST node structure
class Node
{
public:
    int val;
    int count;
    Node *left;
    Node *right;

    // Constructor
    Node(int num1, int num2)
    {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
};

// Function to addNode and find the smaller elements on the right side
int addNode(Node *&root, int value, int countSmaller)
{
    if (root == NULL)
    {
        root = new Node(value, 0);
        return countSmaller;
    }
    if (root->val < value)
    {
        return root->count + addNode(root->right, value, countSmaller + 1);
    }
    else
    {
        root->count++;
        return addNode(root->left, value, countSmaller);
    }
}

// Driver code
int main()
{
    FAST
    in(t) 
    while (t--)
    {
        // inputting values
        in(n)
        in(m) 
        int sz = n * m; // size of the hall
        vector<pii> v(sz); // vector of pairs to store level of sight along with index of teh person
        re(i, m * n)
        {
            cin >> v[i].x;
            v[i].y = i + 1;
        }
        ll sum = 0;
        sort(v.begin(), v.end()); // sorting the people according to their level of sight
        for (int i = 0; i < n * m; i += m)
        {
            int size = m;
            vector<pii> vv; // vector of pairs to store the next m people, along with their index
            for (int j = i; j < i + m; j++)
            {
                vv.pb({v[j].y, v[j].x});
            }
            //sorting according to the index
            sort(vv.begin(), vv.end());
            //arranging according to their entry from last
            reverse(vv.begin(), vv.end());
            int data[m];    // contains the level of sight of the chosen m people
            re(j, m)
            {
                data[j] = vv[j].y;
            }
            int ans[size] = {0};
            // using BST to find the elements smaller than the current element, i.e. finding the number of people with lesser level of sight, already sitting in the row, which is equal to the inconvinience caused to the current person.
            Node *root = NULL;

            for (int i = size - 1; i >= 0; i--)
            {
                ans[i] = addNode(root, data[i], 0);
            }
            for (int i = 0; i < size; i++)
                sum += ans[i];
        }
        // final answer
        cout << sum << endl;
    }
    return 0;
}