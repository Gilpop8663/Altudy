/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `3
// 1
// 7
// 99
// 321
// 777
// 0`;

const input = filePath
  .toString()
  .trim()
  .split("\n")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  const n = input[0];
  const len = input.length;
  for (let i = 1; i < len; i++) {
    const number = input[i];
    if (number === 0) break;
    if (number % n === 0) {
      console.log(`${number} is a multiple of ${n}.`);
      continue;
    }
    console.log(`${number} is NOT a multiple of ${n}.`);
  }
};

/* solve end */

/* print output */
solution(input);
/* print output end */
