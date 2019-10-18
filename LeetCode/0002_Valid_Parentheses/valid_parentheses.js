/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = {
        "{" : "}",
        "[" : "]",
        "(" : ")"
    }

    let pStack = [];
    for(const c of s){
        if(map[c])
            pStack.push(map[c]);
        else
            if(c !== pStack.pop())
                return false;
    }
    return pStack.length === 0;
};
