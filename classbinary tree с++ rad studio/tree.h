//---------------------------------------------------------------------------
#include <algorithm>
#include <vector>

#ifndef treeH
#define treeH
//---------------------------------------------------------------------------
using namespace std;

class binarytree {
private:
struct node {
		int value;
		node *prev = nullptr, *nextL = nullptr, *nextR = nullptr;

		node(int v = 0) {
			value = v;
		}
	};
	node *root;

	int level(node *cur) {
		int mx = 1;
		if (cur->nextL != nullptr)
			mx = max(mx, level(cur->nextL) + 1);
		if (cur->nextR != nullptr)
			mx = max(mx, level(cur->nextR) + 1);
		return mx;
	}

	void dfs(int x, int y, node *cur, vector<vector<int>> &ar, int step) {
		ar[x][y] = cur->value;
		if (cur->nextL != nullptr)
			dfs(x + 1, y - (1 << step), cur->nextL, ar, step - 1);
		if (cur->nextR != nullptr)
			dfs(x + 1, y + (1 << step), cur->nextR, ar, step - 1);
	}

	node *upperBound(node *cur, int v) {
		node *cnode = nullptr;
		int cv = 0x3f3f3f3f;
		while (true) {
			if (v == cur->value)
				return cur;
			if (v < cur->value && cv > cur->value)
				cv = cur->value, cnode = cur;

			if (v <= cur->value) {
				if (cur->nextL == nullptr)
					return cnode;
				else
					cur = cur->nextL;
			}
			else {
				if (cur->nextR == nullptr)
					return cnode;
				else
					cur = cur->nextR;
			}
		}
	}

public:

	binarytree(int v = 0) {
		root = new node(v);
	}

	void add(int v) {
		node *cur = this->root;
		while (true) {
			if (v == cur->value)
				return;
			if (v <= cur->value) {
				if (cur->nextL == nullptr) {
					cur->nextL = new node(v);
					cur->nextL->prev = cur;
					return;
				}
				else
					cur = cur->nextL;
			}
			else {
				if (cur->nextR == nullptr) {
					cur->nextR = new node(v);
					cur->nextR->prev = cur;
					return;
				}
				else
					cur = cur->nextR;
			}
		}
	}

	bool search(int v) {
		node *cur = upperBound(this->root, v);
		return cur != nullptr && cur->value == v;
	}

     void deleteNode(int v) {
        node*cur = upperBound(this->root, v);
        if (cur == nullptr || cur->value != v)
            return;
        if (cur->nextL == nullptr && cur->nextR == nullptr) {
            if (cur->prev == nullptr)
                exit(0);
            node* parent = cur->prev;
            if (parent->nextL == cur)
                parent->nextL = nullptr;
            else
                parent->nextR = nullptr;
            delete cur;
        }
        else if (bool(cur->nextL != nullptr) + bool(cur->nextR != nullptr) == 1) {
            node* parent = cur->prev, *newcur;
            if (cur->nextL != nullptr)
                newcur = cur->nextL;
            else
                newcur = cur->nextR;

            if (newcur->nextL != nullptr)
                newcur->nextL->prev = cur;
            if (newcur->nextR != nullptr)
                newcur->nextR->prev = cur;

            cur->nextL = newcur->nextL;
            cur->nextR = newcur->nextR;
            cur->value = newcur->value;
            delete newcur;
        }
        else {
            node *parent = cur->prev;
            node *mnR = upperBound(cur->nextR, cur->value);

            if (mnR->nextL != nullptr)
                mnR->nextL->prev = cur;
            if (mnR->nextR != nullptr)
                mnR->nextR->prev = cur;

            node *mnPar = mnR->prev;
            if (mnPar->nextL == mnR)
                mnPar->nextL = nullptr;
            else
                mnPar->nextR = nullptr;

            if (cur->nextR == nullptr)
                cur->nextR = mnR->nextR;
            cur->value = mnR->value;
            delete mnR;
        }
    }

	vector<vector<int>>showtree() {
		int n = level(this->root), m = (1 << n) - 1;
		vector<vector<int>>ar(n, vector<int>(m));
		for (int i=0; i < n; i++) {
			for (int j=0; j < m; j++){
				ar[i][j]=0x3f3f3f3f;
			}
		}
		dfs(0, m / 2, this->root, ar, n - 2);
		return ar;
	}
};



#endif
