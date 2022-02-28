const int charset = 26;
struct TrieGraph
{
    struct trie_node
    {
        int next[charset];
        int fail;
        int cnt;
        int end;
        trie_node() : end(0), fail(0), cnt(0) {}
        void init() { memset(next, 0, sizeof(next)); }
    };
    vector<trie_node> nodes;
    vector<int> bfs_q;
    vector<int> match_cnt;
    map<int, int> id2node;
    map<int, int> str_size;
    int match_p;
    void init(int size)
    {
        nodes.clear();
        nodes.reserve(size);
        nodes.push_back(trie_node());
        nodes.back().init();
        match_p = 0;
    }
    static inline int getindex(char c) { return c - 'a'; }
    void insert(const char* s, int id)
    {
        const char* s0 = s;
        int p = 0;
        for (;*s; ++s)
        {
            if (nodes[p].next[getindex(*s)])
            {
                p = nodes[p].next[getindex(*s)];
            }
            else
            {
                int np = nodes.size();
                nodes[p].next[getindex(*s)] = np;
                nodes.push_back(trie_node());
                nodes.back().init();
                p = np;
            }
        }
        ++nodes[p].cnt;
        id2node[id] = p;
        str_size[id] = s - s0;
    }
    void build()
    {
        bfs_q.clear();
        bfs_q.reserve(nodes.size());
        queue<int> q;
        for (int i = 0; i < charset; ++i)
            if (nodes[0].next[i]) q.push(nodes[0].next[i]);
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            bfs_q.push_back(p);
            for (int i = 0; i < charset; ++i)
            {
                if (nodes[p].next[i])
                {
                    nodes[nodes[p].next[i]].fail = nodes[nodes[p].fail].next[i];
                    q.push(nodes[p].next[i]);
                }
                else nodes[p].next[i] = nodes[nodes[p].fail].next[i];
            }
        }
    }
    int match(char c)
    {
        match_p = nodes[match_p].next[getindex(c)];
        return match_p;
    }
    int query(const char* s) // 有多少个出现
    {
        int ret = 0;
        match_cnt.resize(nodes.size());
        for (int i = match_cnt.size() - 1; i >= 0; --i)
        {
            match_cnt[i] = nodes[i].cnt;
        }
        for (const char* ps = s; *ps; ps++)
        {
            for (int p = match(*ps); p && ~match_cnt[p]; p = nodes[p].fail)
                ret += match_cnt[p], match_cnt[p] = -1;
        }
        return ret;
    }
    ll query_sum(const char* s, int wc[]) // 每个分别出现多少
    {
        vector<int> sum;
        sum.resize(nodes.size());
        match_p = 0;
        for (const char* ps = s; *ps; ps++)
        {
            for (int p = match(*ps); p; p = nodes[p].fail)
            {
                sum[p] += nodes[p].cnt;
            }
        }
        ll ret = 0;
        for (map<int, int>::iterator it = id2node.begin(); it != id2node.end(); ++it)
        {
            wc[it->first] = sum[it->second];
            ret += sum[it->second];
        }
        return ret;
    }
    const char* find(const char* s, int& match_id)
    {
        match_p = 0;
        for (const char* ps = s; *ps; ps++)
        {
            for (int p = match(*ps); p; p = nodes[p].fail)
            {
                if (nodes[p].cnt == 0) continue;
                for (map<int, int>::iterator it = id2node.begin(); it != id2node.end(); ++it)
                {
                    if (it->second == p)
                    {
                        match_id = it->first;
                        break;
                    }
                }
                return ps - str_size[match_id] + 1;
            }
        }
        return 0;
    }
};