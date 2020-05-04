struct NODE{
    int ch[26];
};
struct TRIE{
    const static int maxn=1e6;
    NODE node[maxn];
    int cnt;
    inline bool insert(char *s){
        int now=0;bool has=1;
        for(;*s;s++){
            if(!node[now].ch[*s-'a']) has=0,node[now].ch[*s-'a']=++cnt;
            now=node[now].ch[*s-'a'];
        }return has;
    }
};
