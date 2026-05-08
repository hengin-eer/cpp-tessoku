#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int Count = 0;

  for (int x = 1; x <= N; x++) {
    for (int y = 1; y <= N; y++) {
      for (int z = 1; z <= N; z++) {
        if (x + y + z == K)
          Count++;
      }
    }
  }
  cout << Count << endl;
  return 0;
}
