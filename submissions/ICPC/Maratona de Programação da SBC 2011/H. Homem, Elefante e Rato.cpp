#include<bits/stdc++.h>

using namespace std;

#define SegTree SegTreeLazy<Node, op, Lazy, mapping, composition>
template <typename T, auto op, typename L, auto mapping, auto composition>
struct SegTreeLazy {
	int N, size, height;
	const T eT;
	const L eL;
	vector<T> d;
	vector<L> lz;

	explicit SegTreeLazy(int n=0, const T &eT_ = T(), const L &eL_ = L()):
		SegTreeLazy(vector<T>(n, eT_), eT_, eL_) {}
		explicit SegTreeLazy(const vector<T>& v, const T &eT_ = T(), const L &eL_ = L()):
		N(int(v.size())), eT(eT_), eL(eL_) {
			size = 1; height = 0;
			while (size < N) size<<=1, height++;
			d = vector<T>(2*size, eT);
			lz = vector<L>(size, eL);
			for(int i=0; i<N; i++) d[size+i] = v[i];
			for (int i=size-1; i>=1;i--) {
			update(i);
			}
		}
		void set(int p, T x) {
			p += size;
			for(int i= height; i>= 1; i--) push(p>>i);
			d[p] = x;
			for(int i=1; i<=height; i++) update(p>>i);
		}

		T get (int p) {
			p += size;
			for(int i=height; i>=1; i--) push(p>>i);
			return d[p];
		}
		T query(int l, int r) {
			l += size;
			r += size;
			for (int i= height; i>= 1; i--) {
				if(((l >>i) << i) != l) push(l >> i);
				if((((r+1) >> i) <<i) != (r+1)) push(r>>i);
			}
			T sml = eT, smr = eT;
			while(l <= r) {
				if (l&1) sml = op(sml, d[l++]);
				if (!(r &1)) smr = op(d[r--], smr);
				l >>= 1;
				r >>= 1;
			}
			return op(sml, smr);
		}

		T query_all() { return d[1]; }

		void update(int p, L f) {
			p += size;
			for (int i= height; i >= 1; i--) push(p>>i);
			d[p] = mapping(f, d[p]);
			for (int i= 1; i<= height; i++) update(p>>i);
		}

		void update(int l, int r, L f) {
			l += size;
			r += size;
			for(int i= height; i >= 1; i--) {
				if(((l>>i) << i) != l) push(l>>i);
				if((((r+1) >> i) << i) != (r+1)) push(r>>i);
			}

			{
				int l2 = l, r2 = r;
				while(l <= r) {
					if(l & 1) all_apply(l++, f);
					if(!(r &1)) all_apply(r--, f);
					l >>= 1;
					r >>= 1;
				}
				l = l2;
				r = r2;
			}

			for(int i=1; i<=height; i++) {
				if(((l>>i) <<i) != l) update(l >> i);
				if((((r+1) >> i) << i) != (r+1)) update(r>>i);
			}
		}

		//pair<int, int> node_range(int k) const {
		//	int remain = height;
		//	for(int kk =k; kk>>=1; ==remain);
		//	int fst = k << remain;
		//	int lst = min(fst + (1 << remain));
		//	int lst = min(jjkk)
		//}

	private:
		void update(int k) { d[k] = op(d[2*k], d[2*k+1]);}
		void all_apply(int k, L f) {
			//auto [fst, lst] = [&]() {
			//if constexpr (decltype(arg_count(mapping)))() + decltype(arg_count(composition))() > 4)
			//	return node_range();
			//}
			d[k] = mapping(f, d[k]);
			if(k < size) {
				lz[k] = composition(f, lz[k]);
			}
		}
		void push(int k) {
			all_apply(2*k, lz[k]);
			all_apply(2*k+1, lz[k]);
			lz[k] = eL;
		}

};

using Node = array<int, 3>;
Node op(Node A, Node &B) {
	for(int i=0; i<3; i++) {
		A[i] += B[i];
	}
	return A;
}

using Lazy = int;

Node mapping(Lazy f, Node x) {
	//cerr << "Debug: " << f << ' ' << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	for(int i=0; i<f; i++) {
		swap(x[0], x[2]);
		swap(x[1], x[2]);
	}
	//cerr << "Debug: " << f << ' ' << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
	return x;
}

Lazy composition(Lazy f, Lazy g) {
	return (f+g)%3;
}

void solve(int N, int M) {
	Node def = {0};
	SegTree tree(N, def);
	for(int i=0; i<N; i++) {
		tree.set(i, {1, 0, 0});
	}
	while(M--) {
		char op; cin>>op;
		int A, B; cin>>A>>B;
		A--, B--;
		if(op == 'C') {
			auto node = tree.query(A, B);
			cout<<node[0]<<" "<<node[1]<<" "<<node[2]<<"\n";
		} else {
			tree.update(A, B, 1);
		}
	}
	cout<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	while(cin>>N>>M) solve(N, M);
}

// AC, range update, range queries
