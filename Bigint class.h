 An Implementation of BigInteger library in C++

 #ifndef BigInteger_H_INCLUDED
#define BigInteger_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define absBig BigInteger::absBigInteger
#define factBig BigInteger::factBigInteger
#define maxBig BigInteger::maxBigInteger
#define minBig BigInteger::minBigInteger
#define to_Big BigInteger::to_BigInteger
#define revBig BigInteger::revBigInteger
#define countBig BigInteger::countBigInteger
#define eraseBig BigInteger::eraseBigInteger
#define isPaliBig BigInteger::isPaliBigInteger
#define sortBig BigInteger::sortBigInteger
#define powBig BigInteger::powBigInteger

class BigInteger { 

    private:
        string str;

    public:

    BigInteger ()
    {
        str = "0";
    }

    BigInteger (string s)
    {
        if(!isInputCorrect(s)) {
            cerr << "Invalid Input.. Please Use Valid BigInteger" << endl;
            exit(0);
        }
        str = s;        
    }
      BigInteger (int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }

    BigInteger (long long int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }
      BigInteger (const BigInteger &N2)
    {
        if(!isInputCorrect(N2.str)) {
            cerr << "Invalid Input.. Please Use Valid BhimInteger" << endl;
            exit(0);
        }
        str = N2.str;
    }

    // Input Validator
    bool isInputCorrect(string s) {
        if(s[0] == '-')
            s.erase(0, 1);
        for(int i = 0; i < s.length(); ++i) {
            if((int)s[i] < 48 || (int)s[i] > 57)
                return false;
        }
        return true;
    }

    friend ostream &operator<<( ostream &output, const BigInteger &N )
    {
         output<<N.str;
         return output;
    }

    friend istream &operator>>( istream  &input, BigInteger &N )
    {
         input >> N.str;
         return input;
    }

    static BigInteger to_BigInteger(string s)
    {
        BhimInteger N3;
        N3.str = s;
        return N3;
    }

    static BigInteger to_BigInteger(int n)
    {
        BhimInteger N3;
        ostringstream convertstr;
        convertstr << n;
        N3.str = convertstr.str();
        return N3;
    }

    static BigInteger to_BigInteger(long long int n)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << n;
        N3.str = convertstr.str();
        return N3;
    }

   static string removeZero(string str)
    {
        int i = 0, flag = 0;
        if(str[0] == '-')
        {
            flag = 1;
            i++;
        }
        while (str[i] == '0')
           i++;
        if(flag)
            str.erase(1, i);
        else
            str.erase(0, i);
        return str;
    }

    static string add(string s, string s1)
    {
        int carry=0,i,j;
        int sum=0;
        int m=s.length();
        int n=s1.length();
        string y = "";
        if(m == 0 && n == 0)
        {
            y = "0";
        }
        else if(s[0] == '-' && s1[0] == '-')
        {
            y = add(s.erase(0,1), s1.erase(0, 1));
            y = '-' + y;
        }
        else if(s[0] == '-')
        {
            y = subtract(s1, s.erase(0, 1));
        }
        else if(s1[0] == '-')
        {
            y = subtract(s, s1.erase(0, 1));
        }
        else
        {
            vector<int>v;
            for(i=m-1,j=n-1;i>=0||j>=0;i--,j--)
            {
                sum=carry;
                if(i>=0)
                {
                    sum+=s[i]-'0';
                }
                if(j>=0)
                {
                    sum+=s1[j]-'0';
                }
                v.push_back(sum%10);
                carry=sum/10;
            }
            if(carry!=0)
            v.push_back(carry);

            for(i=v.size()-1;i>=0;i--)
                y += (char)(v[i]+48);
        }
        return y;
    }

    static string subtract(string s1,string s2)
    {
        string answer="",ans,temp;
        int carry=0,i,j,k,y=0,flag=0,flag1=0;
        int sum=0;
        if(s1==s2)
        {
            return "0";
        }
        else if(s1[0]=='-' and s2[0]=='-')
        {
            flag1=1;
            s1=s1.substr(1);
            s2=s2.substr(1);
        }
        else if(s1[0]=='-' and s2[0]!='-')
        {
            s1=s1.substr(1);
            answer=add(s1,s2);
            answer='-'+answer;
            return answer;
        }
        else if(s1[0]!='-' and s2[0]=='-')
        {
            s2=s2.substr(1);
            answer=add(s1,s2);
            return answer;
        }
        ans=maxCompare(s1,s2);
        if(ans==s2)
        {
            temp=s1;
            s1=s2;
            s2=temp;
            flag=1;
        }
        int m=s1.length();
        int n=s2.length();
        if(m>n)
        k=m;
        else
        k=n;
        int A[k+1]={0};
        for(i=m-1,j=n-1;i>=0||j>=0;i--,j--)
        {
            sum=0;
            if(i>=0)
            {
                sum+=s1[i]-'0';
            }
            if(j>=0)
            {
                if(sum<s2[j]-'0'+carry)
                {
                    sum+=10;
                    sum-=s2[j]-'0'+carry;
                    carry=1;
                }
                else
                {
                    sum-=s2[j]-'0'+carry;
                    carry=0;
                }
            }
            if(carry!=0 and j<0)
            {
              if(sum<carry)
              {
                sum+=10;
                sum-=carry;
                carry=1;
              }
              else
              {
                sum-=carry;
                carry=0;
              }
            }
            A[y++]=sum;
            //carry=sum/10;
        }
        for(i=k-1;i>=0;i--)
        {
            answer += (char)(A[i] + 48);
        }
        answer=removeZero(answer);
        if(flag1==1 and flag==0)
        {
            answer='-'+answer;
        }
        else if(flag1==0 and flag==1)
        {
            answer='-'+answer;
        }
        return answer;
    }

    static string multiply(string s, string s1)
    {
        int flag=0;
        int m=s.length();
        int n=s1.length();
        int A[m+n]={0};
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int mul=(s[i]-'0')*(s1[j]-'0');
                int sum=A[i+j+1]+mul;
                A[i+j]+=sum/10;
                A[i+j+1]=sum % 10;
            }
        }
        string finalanswer = "";
        for(int i=0;i<m+n;i++)
        {
            if(A[i]==0 && flag==0 ){}
                else if(A[i]!=0 )
                    flag=1;

            if(flag==1)
                finalanswer += (char)(A[i]+48);
        }
        if(finalanswer.length() == 0)
            finalanswer = "0";
        return finalanswer;
    }

    BigInteger operator++()
    {
        string s = "1";
        str = add(this->str,s);
        return *this;
    }

    BigInteger operator--()
    {
        string s = "1";
        str = subtract(this->str,s);
        return *this;
    }

    BigInteger operator++(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = add(this->str,s);
        return N3;
    }

    BigInteger operator--(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = subtract(this->str,s);
        return N3;
    }
       string finalanswer = "";
        for(int i=0;i<m+n;i++)
        {
            if(A[i]==0 && flag==0 ){}
                else if(A[i]!=0 )
                    flag=1;

            if(flag==1)
                finalanswer += (char)(A[i]+48);
        }
        if(finalanswer.length() == 0)
            finalanswer = "0";
        return finalanswer;
    }

    BigInteger operator++()
    {
        string s = "1";
        str = add(this->str,s);
        return *this;
    }

    BigInteger operator--()
    {
        string s = "1";
        str = subtract(this->str,s);
        return *this;
    }

    BigInteger operator++(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = add(this->str,s);
        return N3;
    }

    BigInteger operator--(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = subtract(this->str,s);
        return N3;
    }
     friend BigInteger operator *(BigInteger &N1,int num)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = multiply(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator /(BigInteger &N1,int num)
    {
        BigInteger N3;
        N3.str = division(N1.str,(long long int)num);
        return N3;
    }

    friend BigInteger operator +(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = add(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator -(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = subtract(N3.str,N1.str);
        return N3;
    }

    friend BigInteger operator *(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = multiply(N1.str,N3.str);
        return N3;
    }
  friend BhimInteger operator /(int num, BhimInteger &N1)
    {
        BhimInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        string s2 = N1.str;
        stringstream convertnum(s2);
        long long int div = 0;
        convertnum>>div;
        N3.str = division(N3.str,div);
        return N3;
    }

    static string division(string s1, long long int div)
    {
        string result;
        int index = 0;
        long long int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp*10 + (s1[++index] - '0');

            if(index >= s1.length())
                break;
        }


        while (s1.length() > index) {
            result += (temp / div) + '0';
            temp = (temp % div)*10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }

    static string division(string s1, int div)
    {
        string result;
        int index = 0;
        int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp*10 + (s1[++index] - '0');

            if(index >= s1.length())
                break;
        }


        while (s1.length() > index) {
            result += (temp / div) + '0';
            temp = (temp % div)*10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }

    