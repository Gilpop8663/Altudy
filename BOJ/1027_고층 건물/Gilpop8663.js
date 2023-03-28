/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `15
// 1 5 3 2 6 3 2 6 4 2 5 7 3 1 5`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = Number(input[0]);

  const arr = input[1].split(" ").map((item) => +item);

  const count = Array.from({ length: 55 }, () => 0);

  for (let i = 0; i < n; i++) {
    let maxHeight = -1000000009;
    for (let j = i + 1; j < n; j++) {
      const deg = (arr[j] - arr[i]) / (j - i);
      if (deg > maxHeight) {
        maxHeight = deg;
        count[i] += 1;
        count[j] += 1;
      }
    }
  }

  let answer = 0;
  for (let i = 0; i < n; i++) {
    answer = Math.max(answer, count[i]);
  }
  console.log(answer);
};

/* solve end */

/* print output */
solution(input);
/* print output end */
