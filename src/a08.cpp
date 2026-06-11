#include <iostream>
using namespace std;

int H, W, Q;
int X[1509][1509];
int Sum[1509][1509];
int A[100009], B[100009], C[100009], D[100009];
int Ans[100009];

int main() {
  cin >> H >> W;
  for (int h = 1; h <= H; h++)
    for (int w = 1; w <= W; w++)
      cin >> X[h][w];

  cin >> Q;
  for (int q = 1; q <= Q; q++)
    cin >> A[q] >> B[q] >> C[q] >> D[q];

  // x, yの両軸で行ごと列ごとの累積和を計算する
  Sum[0][0] = 0;
  Sum[0][1] = 0;
  Sum[1][0] = 0;
  for (int h = 1; h <= H; h++)
    for (int w = 1; w <= W; w++)
      Sum[h][w] = Sum[h - 1][w - 1] + X[h][w];

  for (int q = 1; q <= Q; q++)
    Ans[q] = Sum[C[q]][D[q]] - Sum[A[q] - 1][D[q]] - Sum[C[q]][B[q] - 1] +
             Sum[A[q] - 1][B[q] - 1];

  for (int q = 1; q <= Q; q++)
    cout << Ans[q] << "\n";

  return 0;
}
