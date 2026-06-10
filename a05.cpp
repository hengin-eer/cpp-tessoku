#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int Count = 0;

  for (int x = 1; x <= N; x++) {
    for (int y = 1; y <= N; y++) {
      // 2変数のみループを回し、条件式から求まるzが制約を満たしているかチェックする
      int z = K - (x + y);
      if (z >= 1 && z <= N)
        Count++;
    }
  }
  cout << Count << endl;
  return 0;
}
