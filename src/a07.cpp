#include <iostream>
using namespace std;

int main() {
  int D, N, L[100009], R[100009];
  int Bef[100009], Ans[100009];
  // input
  cin >> D >> N;
  for (int i = 1; i <= N; i++)
    cin >> L[i] >> R[i];

  // 各日の前日比を配列に取る
  for (int i = 1; i <= N; i++) {
    Bef[L[i]] += 1;
    // NOTE: R[i + 1]としないように気を付ける
    // 意味: Rで指定している日の翌日から引く: R+1日になったらその人は去るため
    Bef[R[i] + 1] -= 1;
  }

  // 初日スタートから前日比を利用して累積和を計算する
  Ans[0] = 0;
  for (int day = 1; day <= D; day++)
    Ans[day] = Ans[day - 1] + Bef[day];

  // output
  for (int day = 1; day <= D; day++)
    cout << Ans[day] << "\n";

  return 0;
}
