#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string s) {
	int n = s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while ((i + z[i] < n) and (s[z[i]] == s[i + z[i]]))
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}
int main()
{
    string line;
    getline(cin, line);
    vector<int> z = z_function(line);
    for (int i = 0; i < z.size(); i++){
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}
