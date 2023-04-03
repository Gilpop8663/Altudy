/* get input */
const fs = require('fs');

const filePath = fs.readFileSync('/dev/stdin');

// const filePath = `123456789123456789123456789123456789123456789123456789123456789123456789`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = input => {
  const n = BigInt(input);
  const m = BigInt(20000303);
  console.log((n % m).toString());
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
