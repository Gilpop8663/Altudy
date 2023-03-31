/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `10
// 1 100 2 50 60 8 7 3 6 5`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = +input[0];
  const arr = input[1].split(" ").map((item) => +item);

  const dp = Array.from({ length: n }, () => 0);

  for (let i = n - 1; i >= 0; i--) {
    dp[i] = arr[i];

    for (let j = n - 1; j > i; j--) {
      if (arr[j] < arr[i]) {
        dp[i] = Math.max(dp[i], dp[j] + arr[i]);
      }
    }
  }

  let answer = 0;
  for (let i = 0; i < n; i++) {
    answer = Math.max(dp[i], answer);
  }
  console.log(answer);
};

/* solve end */

/* print output */
solution(input);
/* print output end */
