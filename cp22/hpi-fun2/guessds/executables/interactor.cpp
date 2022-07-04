#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

struct AbstractDS {
    virtual void insert(int x) = 0;
    virtual bool empty() = 0;
    virtual int remove() = 0;
};

struct myQueue : public AbstractDS {
    queue<int> q;
    void insert(int x) {q.push(x);}
    bool empty() {return q.empty();}
    int remove() {
        int res = q.front();
        q.pop();
        return res;
    }
};

struct myStack : public AbstractDS {
    vector<int> s;
    void insert(int x) {s.push_back(x);}
    bool empty() {return s.empty();}
    int remove() {
        int res = s.back();
        s.pop_back();
        return res;
    }
};

struct mySet : public AbstractDS {
    set<int> s;
    void insert(int x) {s.insert(x);}
    bool empty() {return s.empty();}
    int remove() {
        int res = *s.begin();
        s.erase(s.begin());
        return res;
    }
};

struct myPQ : public AbstractDS {
    priority_queue<int, vector<int>, greater<int>> pq;
    void insert(int x) {pq.push(x);}
    bool empty() {return pq.empty();}
    int remove() {
        int res = pq.top();
        pq.pop();
        return res;
    }
};


int main(int argc, char* argv[]) {
    setName("describe your interactor here");
    registerInteraction(argc, argv);

    // Use inf (.in file) and ans (.ans file).
    // Read queries from the solution using ouf, and write to it using cout.
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf).
    // Remember that you should probably have a query limit and enforce it.


    string type = inf.readToken("queue|stack|set|pq");

    AbstractDS* used_ds = nullptr;
    if(type=="queue") used_ds = new myQueue;
    if(type=="stack") used_ds = new myStack;
    if(type=="set") used_ds = new mySet;
    if(type=="pq") used_ds = new myPQ;

    for(int queriesRemaining = 32; queriesRemaining>=0; --queriesRemaining) {
        
        string t = ouf.readToken("!|?");
        if (t == "?") {
            if(queriesRemaining==0)
                break;

            string query = ouf.readToken("insert|empty|remove");
            if (query == "insert")
                used_ds->insert(ouf.readInt(0,100));
            if (query == "empty")
                cout << (used_ds->empty() ? "yes" : "no") << endl;
            if (query == "remove") {
                if (used_ds->empty()) 
                    quit(_wa, "remove from empty datastracture");
                cout << used_ds->remove() << endl;
            }
        } 
        if (t == "!") {
            string result = ouf.readToken(type);
            quit(_ok, "you guessed right");
        }
    }

    cout << -1 << endl;
    quit(_wa, "too many queries");

}
