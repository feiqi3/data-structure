
#include<string>
#include<iostream>
#include"SeqStack.cpp"
/*

（1）如果堆栈是空的，直接将操作符存储到堆栈中

（2）如果该操作符的优先级大于堆栈出口的操作符，就直接将操作符存储到堆栈中

（3）如果该操作符的优先级低于堆栈出口的操作符，就将堆栈出口的操作符导出, 直到该操作符的优先级大于堆栈顶端的操作符。

    将扫描到的操作符导入到堆栈中。
*/
typedef stack<char> cstack;
class suffixExpr
{
public:

    std::string express() { return out; }

    suffixExpr(std::string& k)
    {
        cstack cs;
        int i = 0;
        while (i < k.length())
        {
            char tmp = k[i];
            int tp = operOrnum(tmp);
            char top;
            int weight;
            switch (tp)
            {
                //把数字放入队列中
            case 1:
                inList(out, tmp);
                i++;
                break;
                //按优先级决定操作符的去向
            case 2:
                if (cs.isEmpty())
                {
                    cs.push(tmp);
                    i++;
                    break;
                }
                //右括号匹配
                if (tmp == ')') {
                    while (true)
                        if ((top = cs.top()) != '(')
                            inList(out, top);
                        else {
                            i++;
                            cs.pop();
                            break;
                        }
                    break;
                }
                top = vTop(cs);
                weight = priority(tmp);
                //权重大于栈顶的，压栈
                if ( top=='(' || weight > priority(top))
                {
                    cs.push(tmp);
                    i++;
                    break;
                }
                else if (weight <= priority(top))
                {
                    inList(out, cs.top());
                    break;
                }
                break;
                //直接报错
            case 3:
                return;
            default:
                break;
            }
        }
        if (!cs.isEmpty()) {
            int len = cs.length();
            for (int i = 0; i < len; i++)
                inList(out, cs.top());
        }
    }

    int caculator() 
    {
        float sum = 0;
        stack<int> cs;
        int i = 0;
        while (i < out.length()) 
        {
            char c = out[i];
            i++;
            if (operOrnum(c) == NUM)
                cs.push(int(c - '0'));
            else
            {
                int a = cs.top();
                int b = cs.top();
                if (c == '+')
                    cs.push(a + b);
                else if (c == '-')
                    cs.push(b - a);
                else if (c == '*')
                    cs.push(a * b);
                else if (c == '/')
                    cs.push(b / a);
            }
        }
        return cs.top();
    }

private:

    std::string out;

    enum type
    {
        NUM = 1,//number
        OPR = 2,//operator
        UDF = 3 //undefine
    };

    enum weight
    {
        plus = 1,
        multi = 2,
        bracket = 3,
        rbracket = -1
    };

    char vTop(cstack cs)
    {
        char c = cs.top();
        cs.push(c);
        return c;
    }
    //判断是数字还是操作符
    int operOrnum(char c)
    {
        if (c >= 48 && c <= 57)
            return NUM;
        else if (c == '+' || c == '-' || c == '*' || c == '/'||c=='('||c==')')
            return OPR;
        else
            return UDF;
    }
    //压入字符串中
    void inList(std::string& tar, char c) { tar.append(1, c); }
    //返回符号的优先级
    int priority(char c)
    {
        if (c == '(')
            return bracket;
        else if (c == '*' || c == '/')
            return multi;
        else if (c == '+' || c == '-')
            return plus;
        else if (c == ')')
            return rbracket;
    }
};
int main()
{
    std::string a = "1+2*3";
    suffixExpr se(a);
    std::cout << se.express() << "\n";
    std::cout<<se.caculator();
}