class Solution:
    def simplifyPath(self, path: str) -> str:

        stack = []
        for part in filter(None, path.split("/")):
            if part == "..":
                if stack:
                    stack.pop()
            elif part != '.':
                stack.append(part)
        
        return "/" + "/".join(stack)