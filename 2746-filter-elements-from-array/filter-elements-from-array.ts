type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    const ans: number[] = []

    arr.forEach((n, i)=> {
        if (fn(n, i))
            ans.push(n)
    })
    return ans;
};
