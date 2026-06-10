#include <iostream>
using namespace std;

int main() {
  int N, Q;
  int A[10009], L[100009], R[100009], Sum[100009];

  // データの入力
  cin >> N >> Q;
  for (int i = 1; i <= N; i++)
    cin >> A[i];
  for (int i = 1; i <= Q; i++)
    cin >> L[i] >> R[i];

  // 累積和の作成
  Sum[0] = 0;
  for (int i = 1; i <= N; i++)
    // 配列Aを1要素ずつ加算した値の配列になる
    Sum[i] = Sum[i - 1] + A[i];

  // 累積和を用いた出力
  for (int i = 1; i <= Q; i++) {
    int left = L[i - 1];
    int right = R[i];
    // NOTE: endlを忘れない
    cout << Sum[right] - Sum[left] << endl;
  }

  return 0;
}
