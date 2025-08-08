
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined

function once(fn: Function): OnceFn {
    let called: boolean = false;

    return function (...args) {
        if (!called)
        {
            called = true;
            return fn(...args);
        }
        return undefined;
    };
}
