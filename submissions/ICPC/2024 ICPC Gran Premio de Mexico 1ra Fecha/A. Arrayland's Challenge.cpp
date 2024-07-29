#include  <bits/stdc++.h>
using namespace std;
template <typename T, typename Tans>
struct Mo {
        struct Query {
                int l, r, idx, block;

                Query(int _l, int _r, int _idx, int _block)
                    : l(_l),
                      r(_r),
                      idx(_idx),
                      block(_block) {}

                bool operator<(const Query &q) const {
                        if (block != q.block)
                                return block < q.block;
                        return (block & 1 ? (r < q.r)
                                          : (r > q.r));
                }
        };

        vector<T> xs;
        vector<Query> qs;
	multiset<int> diffs, vals;
        const int block_size;

        Mo(const vector<T> &a)
            : xs(a),
              block_size((int)ceil(sqrt(a.size()))) {}

        void add_query(int l, int r) {
                qs.emplace_back(l, r, qs.size(),
                                l / block_size);
        }

        auto solve() {
                // get answer return type
                vector<Tans> answers(qs.size());
                sort(qs.begin(), qs.end());

                int cur_l = 0, cur_r = -1;
                for (auto q : qs) {
                        while (cur_l > q.l) add(--cur_l);
                        while (cur_r < q.r) add(++cur_r);
                        while (cur_l < q.l) remove(cur_l++);
                        while (cur_r > q.r) remove(cur_r--);
                        answers[q.idx] = get_answer();
                }

                return answers;
        }

       private:
        // add value at idx from data structure
        inline void add(int i) {
		auto xi = xs[i];		
		
		auto it = vals.upper_bound(xi);
		if (it != vals.end()) {
			diffs.emplace(*it-xi);
		}
		if (it != vals.begin()) {
			diffs.emplace(xi - *prev(it));
		}

		if (it != vals.begin() and it != vals.end()) {
			diffs.extract(*it-*prev(it));
		}
		vals.emplace(xi);
	}

        // remove value at idx from data structure
        inline void remove(int i) {
		auto xi = xs[i];		

		vals.extract(xi);
		auto it = vals.upper_bound(xi);
		if (it != vals.end()) {
			diffs.extract(*it-xi);
		}
		if (it != vals.begin()) {
			diffs.extract(xi - *prev(it));
		}

		if (it != vals.end() and it != vals.begin())
			diffs.emplace(abs(*it-*prev(it)));

	}

        // extract current answer of the data structure
        inline Tans get_answer() {
		return *diffs.begin();
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> XS(N);
	for (auto& xi : XS)
		cin >> xi;

	Mo<int, int> mo(XS);

	int Q;
	cin >> Q;

	while (Q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		mo.add_query(l, r);
	}

	auto ans = mo.solve();

	for (auto i : ans) cout << i << '\n';
	cout << '\n';
}

// AC, Mo's Algorithm
