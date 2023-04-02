/* get input */
const fs = require('fs');

const filePath = fs.readFileSync('/dev/stdin');

// const filePath = `abcdabcabb`;

const input = filePath.toString().trim().split('\n');
/* get input end */

/* set param */

/* set param end */

/* solve */
const getFail = str => {
  const n = str.length;

  const failArr = Array.from({ length: n }, () => 0);

  let j = 0;

  for (let i = 1; i < n; i++) {
    while (j > 0 && str[i] !== str[j]) {
      j = failArr[j - 1];
    }

    if (str[i] === str[j]) {
      failArr[i] = j + 1;
      j += 1;
    } else {
      failArr[i] = 0;
    }
  }

  return failArr;
};

const solution = input => {
  const str = input[0];

  const stringMap = new Map();

  const n = str.length;

  let answer = 0;

  for (let i = 0; i < n; i++) {
    const word = str.slice(i, n);

    answer = Math.max(answer, Math.max(...getFail(word)));
  }

  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
