#include <iostream>
#include <vector>

using namespace std;

int LookingForSmall(vector<int> &a, int &n) {
  int most;

  for (int i = 0; i < a.size(); ++i) {
	int sum = 0;
	for (int j = i; j < a.size(); ++j) {
	  if (a[i] == a[j])
		sum++;
	  if (sum > n / 2) {
		most = a[i];
		return most;
	  }
	}
  }
}

int main() {
  int n;
  vector<int> a;
  int aa;
  cin >> n;
  while (cin >> aa) {
	a.push_back(aa);
	if (cin.peek() == '\n') {
	  break;
	}
  }
  cout << LookingForMost(a, n);
};
