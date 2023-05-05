/* get input */
const fs = require('fs');

const filePath = fs.readFileSync('/dev/stdin');

// const filePath = `20`;

const input = filePath.toString();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = input => {
  const n = BigInt(input);
  if (n === 0) {
    console.log(0);
    return;
  }

  let ans = 1n;
  for (let i = 1; i <= n; i++) {
    ans *= BigInt(i);
  }

  console.log(ans.toString());
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
