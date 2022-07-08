#include <bits/stdc++.h>
using namespace std;

int fn;

struct cnode
{
    int cn;
    int pn;
    int hn;
    int gn;
};
typedef pair<cnode, int> state;
struct cmp
{
    bool operator()(state p1, state p2)
    {
        return p1.second > p2.second;
    }
};

priority_queue<state, vector<state>, cmp> q;
vector<cnode> node;
priority_queue<state, vector<state>, cmp> bpath;
vector<state> path;

int main()
{
    int cn, pn, hn, gn, en, sn, fn;
    bool in;

    int j = 111;
    int k = 111;

    do
    {
        cout << "Enter the following properties of node" << endl;
        cout << "Enter the current node: ";
        cin >> cn;
        cout <<endl<< "Enter the parent node: " ;
        cin >> pn;
        cout  << endl<< "Enter the heuristic value of node:";
        cin >> hn;
        cout<< endl << "Enter the cost of path: " ;
        cin >> gn;
        cout<< endl;
        node.push_back({cn, pn, hn, gn});

        cout << "Do you want to add more nodes(1 -> yes or 0 -> no):" << endl;
        cin >> in;
    } while (in);

start:
    cout << "Enter the start node:" << endl;
    cin >> sn;

    for (int i = 0; i < node.size(); i++)
    {
        if (node[i].cn == sn)
        {

            j = i;
        }
    }
    if (j == 111)
    {
        cout << "Entered start node is not valid" << endl;
        goto start;
    }

end:
    cout << "Enter the goal node:" << endl;
    cin >> en;
    for (int i = 0; i < node.size(); i++)
    {
        if (node[i].cn == en)
        {
            k = i;
        }
    }
    if (k == 111)
    {
        cout << "Entered goal node is not valid" << endl;
        goto end;
    }
    node[k].hn = 0;
    fn = node[j].gn + node[j].hn;
    q.push(state(node[j], fn));

    while (!(q.top().first.cn == en))
    {
        state tnode = q.top();
        path.push_back(q.top());
        q.pop();
        for (int i = 0; i < node.size(); i++)
        {

            if (node[i].pn == tnode.first.cn)
            {

                node[i].gn = node[i].gn + q.top().first.gn;
                fn = node[i].gn + node[i].hn;

                q.push(state(node[i], fn));
            }
        }
    }
    path.push_back(q.top());
    q.pop();
    cout<< "The shortest path is :"<<endl;
    int l = path.size() - 1;
    bpath.push(path[l]);
    cout << bpath.top().first.cn;
    while (!(bpath.top().first.cn == sn))
    {
        state tpath = bpath.top();

        bpath = priority_queue<state, vector<state>, cmp>();
        for (int i = 0; i < path.size(); i++)
        {

            if (path[i].first.cn == tpath.first.pn)
            {
                bpath.push(path[i]);
            }
        }
        cout << " <-- " << bpath.top().first.cn;
    }
}
