type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let ans: number = init
    
    nums.forEach(num =>{
        ans = fn(ans, num);
    });
    return ans;
};