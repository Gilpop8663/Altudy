/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `2735 1`;

const input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = input[0];
  const k = input[1];

  const arr = [];

  for (let i = 1; i <= n; i++) {
    if (n % i === 0) {
      arr.push(i);
    }
  }
  if (arr.length < k) {
    console.log(0);
  } else {
    console.log(arr[k - 1]);
  }
};

/* solve end */

/* print output */
solution(input);
/* print output end */
