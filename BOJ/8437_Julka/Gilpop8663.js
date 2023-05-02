/* get input */
const fs = require('fs');

const filePath = fs.readFileSync('/dev/stdin');

// const filePath = `10
// 2`;

const input = filePath
  .toString()
  .trim()
  .split('\n')
  .map(item => BigInt(item));
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = input => {
  const x = input[0];
  const y = input[1];

  const ans = (x + y) / 2n;

  const ans2 = (x - y) / 2n;

  console.log(ans.toString());
  console.log(ans2.toString());
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
