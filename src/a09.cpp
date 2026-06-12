#include <iostream>
using namespace std;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int Sum[100009][100009], Answer[100009][100009];

int main() {
  cin >> H >> W >> N;
  for (int n = 1; n <= N; n++)
    cin >> A[n] >> B[n] >> C[n] >> D[n];

  // 2次元いもす法で累積和を求める
  Sum[0][0] = 0;
  Sum[0][1] = 0;
  Sum[1][0] = 0;
  for (int n = 1; n <= N; n++) {
    Sum[A[n]][B[n]] += 1;
    Sum[C[n] + 1][D[n] + 1] += 1;
    Sum[A[n]][D[n] + 1] -= 1;
    Sum[C[n] + 1][B[n]] -= 1;
  }

  // 累積和から出力を再現
  Answer[0][0] = 0;
  Answer[0][1] = 0;
  Answer[1][0] = 0;
  for (int w = 1; w <= W; w++)
    for (int h = 1; h <= H; h++)
      Answer[w][h] = Answer[w][h - 1] + Sum[w][h];

  for (int h = 1; h <= H; h++)
    for (int w = 1; w <= W; w++)
      Answer[w][h] = Answer[w - 1][h] + Sum[w][h];

  // output
  for (int w = 1; w <= W; w++) {
    for (int h = 1; h <= H; h++) {
      if (h >= 2)
        cout << " ";
      cout << Answer[w][h];
    }
    cout << "\n";
  }

  return 0;
}
