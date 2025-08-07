function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    for (let j = 0; j < arr.length; j++)
        arr[j] = fn(arr[j], j);
    return arr;
};