// https://www.acmicpc.net/problem/10844
// C11

#include <stdio.h>

#define MOD 1000000000

int dp[101][10];  // dp[i][j] : 길이가 i이고 마지막 숫자가 j인 계단 수의 개수

int main() {
  int N;
  scanf("%d", &N);

  // 초기값 설정 (길이 1에서 1~9까지는 1개씩 존재)
  for (int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }

  // DP 점화식 적용
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j > 0) dp[i][j] += dp[i-1][j-1]; // j == 9 일때 8로만 값이 확정되므로
      if (j < 9) dp[i][j] += dp[i-1][j+1]; // j == 0 일때 1로만 값이 확정되므로
      dp[i][j] %= MOD;
    }
  }

  // 결과 계산 (길이 N에서 0~9까지의 계단 수를 모두 더함)
  long long result = 0;
  for (int i = 0; i <= 9; i++) {
    result += dp[N][i];
  }

  printf("%lld\n", result % MOD);

  return 0;
}

/*
  이건 문제부터 이해안가서 아예 못풀었다
  문제를 이해하기로는 길이가 N인 계단수 라는데..

  길이가 1일때
  계단수는
  1일때 1
  2일때 2
  3일때 3
  ...
  총 9개임 (0제외)

  길이가 2라면?
  1일때 10, 12
  2일때 21, 23
  3일때 32, 34
  ...
  9일때 98
  총 17개임

  길이가 3이라면?
  10일때 ->
  12일때 ->
  21일때 ->
  ...
  98일때 ->
  이런 방식으로 기하급수적으로 늘어남

  일단 dp 초기값으로는
  dp[1][i] = 1,
  길이가 1일때는 모두가 1개씩 존재하므로,

  점화식:
  dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
*/
