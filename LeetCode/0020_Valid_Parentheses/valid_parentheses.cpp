class Solution {
public:
    bool isValid(string s) {
        std::stack<char> pStack;
        for(const auto& c : s){
            switch(c){
                case '{':
                    pStack.push('}');
                    break;
                case '[':
                    pStack.push(']');
                    break;
                case '(':
                    pStack.push(')');
                    break;
                default:
                    if(pStack.size() == 0 || c != pStack.top())
                        return false;
                    else
                        pStack.pop();
            }
        }
        return (pStack.size() == 0) ? true : false;
    }
};
