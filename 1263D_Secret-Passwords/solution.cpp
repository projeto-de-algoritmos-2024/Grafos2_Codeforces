#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

class UFDS {
 public:
  vector<int> ps, size;

  UFDS(int N) : size(N + 1, 1), ps(N + 1){
    iota(ps.begin(), ps.end(), 0);
  }

  int find_set(int x) { return x == ps[x] ? x : (ps[x] = find_set(ps[x])); }

  bool same_set(int x, int y) { return find_set(x) == find_set(y); }

  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (size[px] < size[py]) swap(px, py);

    ps[py] = px;
    size[px] += size[py];
  }
};

int main()
{
    int n;
    cin >> n;

    set<int> letters;
    UFDS ufds(MAX);

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(auto c : s)
        {
            int letter_value = c - 'a';
            int root_value = s[0] - 'a';

            letters.insert(letter_value);
            ufds.union_set(root_value, letter_value);
        }
    }

    vector<int> visited(MAX);
    int ans = 0;
    for(auto v : letters)
    {
        auto root = ufds.find_set(v);

        ans += !visited[root]++;
    }

    cout << ans << "\n";
    return 0;
}
