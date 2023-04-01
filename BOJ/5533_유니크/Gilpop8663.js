/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `3
// 89 92 77
// 89 92 63
// 89 63 77`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = +input[0];
  const arr = [];
  for (let i = 1; i <= n; i++) {
    arr.push(input[i].split(" ").map((item) => +item));
  }

  for (let i = 0; i < n; i++) {
    let totalScore = 0;
    for (let j = 0; j < 3; j++) {
      const myScore = arr[i][j];
      let flag = 0;

      for (let k = 0; k < n; k++) {
        if (i === k) continue;
        if (myScore === arr[k][j]) {
          flag = 1;
          break;
        }
      }

      if (flag === 0) {
        totalScore += myScore;
      }
    }

    console.log(totalScore);
  }
};

/* solve end */

/* print output */
solution(input);
/* print output end */
