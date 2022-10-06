vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}
///   if the distance is 0 or 1
///   simply use a normal queue, and append new vertices at the beginning if the corresponding edge has weight 0, d[u]=d[v]
///   or at the end if(d[u] = d[v]+1.

///   so maximum dif 1. but if the value can 0-k , then the maximum diff k.
///   we can keep k+1  buckets for the vertices in the queue, and whenever the bucket
///   corresponding to the smallest distance gets empty, we make a cyclic shift to get
///   the bucket with the next higher distance. This extension is called Dial's algorithm.
