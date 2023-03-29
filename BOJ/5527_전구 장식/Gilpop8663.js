/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `10
// 1 1 0 0 1 0 1 1 1 0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input[1].split(" ").map((item) => +item);

  const dp = [];

  let cnt = 1,
    prev = arr[0];
  for (let i = 1; i < n; i++) {
    if (arr[i] == prev) {
      dp.push(cnt);
      cnt = 1;
    } else {
      cnt += 1;
      prev = arr[i];
    }
  }
  dp.push(cnt);

  let answer = 0;

  if (dp.length === 1) {
    answer = dp[0];
  } else if (dp.length === 2) {
    answer = dp[0] + dp[1];
  } else {
    for (let i = 0; i < dp.length - 2; i++) {
      answer = Math.max(answer, dp[i] + dp[i + 1] + dp[i + 2]);
    }
  }

  console.log(answer);
};

/* solve end */

/* print output */
const output = solution(input);
/* print output end */
