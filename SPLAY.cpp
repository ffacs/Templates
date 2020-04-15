#include <bits/stdc++.h>
using namespace std;
class SPLAY{
private:
    #define MAXN 100000+5
    #define INF 0x7fffffff
    struct TREE{ 
        int ch[2],siz,fa,val,cnt;
    }tree[MAXN];
    int root,cnt;
    int lc(int p) {return tree[p].ch[0];}
    int rc(int p) {return tree[p].ch[1];}
    int faof(int p) {return tree[p].fa;}
    void up(int p){tree[p].siz=tree[lc(p)].siz+tree[rc(p)].siz+tree[p].cnt;}
    int get(int p){return rc(faof(p))==p;}
    void rotate(int p){
        int fa=faof(p),gfa=faof(fa);
        int d1=get(p),d2=get(fa);
        tree[tree[p].ch[d1 ^ 1]].fa = fa;
        tree[fa].ch[d1] = tree[p].ch[d1 ^ 1];
        tree[p].ch[d1 ^ 1] = fa;tree[fa].fa = p;
        tree[gfa].ch[d2] = p;tree[p].fa = gfa;
        up(fa);up(p);
    }
    void splay(int p, int goal) {
        while (faof(p) != goal) {
            int fa = faof(p), gfa = faof(fa);
            int d1 = get(p), d2 = get(fa);
            if (gfa != goal) {
                if (d1 == d2) rotate(fa);
                else rotate(p);
            }
            rotate(p);
        }
        if (goal == 0) root = p;
    }
public:

    void ins(int val) {
        int now = root, fa = 0;
        while (now && tree[now].val != val)
            fa = now, now = tree[now].ch[tree[now].val < val];
        if (now) tree[now].cnt++;
        else {
            now = ++cnt;
            tree[now].cnt = tree[now].siz = 1;
            tree[now].val = val;
            tree[now].fa = fa;
            tree[fa].ch[tree[fa].val < val] = now;
        }
        splay(now, 0);
    }

    int kth(int k) {
        int now = root;
        while (1) {
            if (tree[lc(now)].siz >= k) now = lc(now);
            else if (tree[lc(now)].siz + tree[now].cnt < k) k -= tree[lc(now)].siz + tree[now].cnt, now = rc(now);
            else return now;
        }
    }

    int getpos(int val) {
        int now = root;
        while (val != tree[now].val && tree[now].ch[tree[now].val < val])
            now = tree[now].ch[tree[now].val < val];
        return now;
    }

    int getrk(int val) {
        splay(getpos(val), 0);
        return tree[lc(root)].siz ;
    }

    int getpf(int val, int kind) {
        splay(getpos(val), 0);
        if ((tree[root].val > val && kind == 1) || (tree[root].val < val && kind == 0)) return root;
        int now = tree[root].ch[kind];
        while (tree[now].ch[kind ^ 1])
            now = tree[now].ch[kind ^ 1];
        return now;
    }

    void del(int val) {
        int pre=getpf(val,0);
        int nex=getpf(val,1);
        splay(pre, 0);
        splay(nex, root);
        int now = lc(rc(root));
        if (tree[now].cnt > 1) {
            tree[now].cnt--;
            splay(now, 0);
        } else tree[rc(root)].ch[0] = 0,splay(rc(root),0);
    }
    SPLAY(){
        root=cnt=0;
        ins(-INF),ins(INF);
    }
    #undef MAXN
    #undef INF
}s;
int main(){
}