#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 9; i >= 0; i--) {
    // 1bをiビット分移動させる = iの二乗
    int divisor = (1 << i);
    cout << (N / divisor) % 2;
  }
  cout << endl;

  return 0;
}
