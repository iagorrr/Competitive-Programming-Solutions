#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ostream& operator<<(ostream& dest, __int128_t value) {
	ostream::sentry s(dest);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char* d = end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) {
			--d;
			*d = '-';
		}
		int len = end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) dest.setstate(ios_base::badbit);
	}
	return dest;
}


string to_string(__int128_t x) {
	string ret;
	for (; x ; x = x/(__int128_t)10) {
		ret.push_back((x%(__int128_t)10)+'0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string sa, sb, sc, sd;
	cin >> sa >> sb >> sc >> sd;
	__int128_t a = stoll(sa), b = stoll(sb), c = stoll(sc), d = stoll(sd);

	int n = sa.size();
	const int maxb = 21;
	for (ll mask = 1ll; mask < (1ll << n); mask++) {
		__int128_t na = 0;
		bitset<maxb> bs(mask);
		__int128_t p10 = 1;
		map<char,int> removed;
		char last = '0';
		for (int i = n-1; i >=0 ; i--) {
			if (bs[i]) {
				na = na +  ((__int128_t)(sa[i]-'0')*p10);
				p10 = p10*(__int128_t)10;
				last = sa[i];
			}
			else 
				removed[sa[i]]++;
		}
		if (last == '0') continue;

		if ((d*na % c) != (__int128_t)0) continue;
		auto x = (d*na)/c;

		auto sx = to_string(x);

		map<char,int> removed2;
		int ix = 0, ib = 0;

		for (; ib < sb.size() and ix < sx.size();) {
			if (sb[ib] == sx[ix]) {
				ib++; ix++;
			}
			else {
				removed2[sb[ib]]++;
				ib++;
			}
		}
		while(ib < sb.size()) {
			removed2[sb[ib]]++;
			ib++;
		}


		if (ix >= sx.size() and removed2 == removed) {
			cout << "possible\n";
			cout << to_string(na)  << ' ' << sx << '\n';
			return 0;
		}

	}

	cout << "impossible\n";
}	
