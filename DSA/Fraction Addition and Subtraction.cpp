class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') expression = "+" + expression;
        int numerator = 0, denominator = 1;
        int n = expression.size();
        int i =0;
        while(i<n){
            int sign=1;
            if(expression[i]=='-') sign = -1;
            i++;
            int num=0;
            while(i<n && expression[i]!='/' ){
                num = num*10 + (expression[i]-'0');
                i++;
            }
            num = num*sign;
            i++; //to ignore '/'
            int deno=0;
            while(i<n && isdigit(expression[i])){
                deno = deno*10 + (expression[i]-'0');
                i++;
            }
            
            numerator = numerator*deno + denominator*num;
            denominator*=deno;
            
            int gcd = abs(__gcd(numerator,denominator));
            numerator/=gcd;
            denominator/=gcd;
        }
        return to_string(numerator)+'/'+to_string(denominator);
    }
};
