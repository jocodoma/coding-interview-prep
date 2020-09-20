/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  if(n < 0) return 0;
  if(n < 3) return n;
  
  let sol = 0;
  let one_step_b4 = 2;
  let two_step_b4 = 1;
  for(let i = 3; i < n+1; i++){
      sol = one_step_b4 + two_step_b4;
      two_step_b4 = one_step_b4;
      one_step_b4 = sol;
  }
  return sol;
};
