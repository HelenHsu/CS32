#include "Map.h"
#include <iostream>
#include <stack>
#include <cctype>
#include <cassert>
#include <stdio.h>
using namespace std;

bool isValid(string infix);
int precedence(char op);
void print(string str);
bool isOperator(char x);
bool calculator(char op, int var1, int var2, int& ans);
bool toPostfix(string& infix,string& postfix);

int evaluate(string infix, const Map& values, string& postfix, int& result)
{
   //check if the infix is valid 
	if (!isValid(infix))
		return 1;			//the infix is not syntactically valid
	cerr<<"infix now is ";
	print(infix);

  //convert infix to postfix
	if(!toPostfix(infix,postfix))
		cerr<<"Something wrong with coverting infix to postfix."<<endl;
	cerr<<"postfix now is ";
	print(postfix);

  //evaluate the postfix
	stack<char> stackC;
	for (int i=0; i<postfix.size();i++)
	{
		char c=postfix[i];
		int var1, var2, ans,v;
		if(islower(c))
			stackC.push(c);
		else
		{
			if(values.get(stackC.top(),v))
				var2=v;
			else
			{	cerr<<"cannot find a mapping value"<<endl; 
				return 2;
			}
			stackC.pop();
			if(values.get(stackC.top(),v))
				var1=v;
			else 
			{	cerr<<"cannot find a mapping value"<<endl;
				return 2;
			}
			stackC.pop();
	
			if(!calculator(c,var1,var2,ans))
				return 3;			//try to devide by 0
			else
				stackC.push(ans);
		}
	}
	result = stackC.top();
	return 0;

	//below is to check if there is only one number left in the stack
/*
	if (stackC.size()==1)
	{
		result = stackC.top();
		return result;
	}
	else
	{	for(int j=0; j<stackC.size();j++)
		{
			cerr<<"The stack contains "<< stackC.top()<<endl;
			stackC.pop();
		}
		cerr<<"There is something wrong with calculation."<<endl;
	}
	return 0;
*/
}

bool isOperator(char x)
{
  if(x!='+'&& x!='-' && x!= '*' && x!='/')
	return false;
  return true;
		
}

bool isValid(string infix)
{
	int k=0,p=0;
	for (int i =0; i<infix.size();i++)
	{
		//count the space
		if (isspace(infix[i]))
			k++;
		if (infix[i]=='(')
			p++;
		if (infix[i]==')')
			p--;
		//count the parenthese, it should be balanced
		if (p<0)
		{	cerr<<"the parenthese number is not right"<<endl;
			return false;		
		}
	}

 	//check if empty infix or all space
	if (k==infix.size())
	{	cerr<<"It's empty."<<endl;
		return false;
	}
	
	//check if parentheses is not the same number
	if (p!=0)
	{
		cerr<<"The number of parenthese is not right."<<endl;
		return false;
	}
	//check if the sequence is right 
	for (int i=0; i<infix.size(); i++)
	{
		char c = infix[i];
		int j= i;
		//the first letter should be either lower case letter or '('
		if (i==0)
		{	//ignore the space
			while(isspace(infix[j])&& j<infix.size()) 
				j++;
			if(!islower(infix[j])&& infix[j]!='(')
			{	
				cerr<<"The first char should be either '(' or a lower letter."<<endl;
				return false;
			}
		}
		
		//lower letter should not be followd by lower case letter or '('
		if (islower(c))
		{
			do{j++;}while(isspace(infix[j])&& j<infix.size());
			if(infix[j]=='('|| islower(infix[j]))
			{	cerr<<"A '(' or a lower case letter after a letter."<<endl;
				return false;
			}
		}

		//the operator should be followed by either a lower case letter or a '('
		if (isOperator(c))
		{
			do{j++;}while(isspace(infix[j])&& j<infix.size());
			if(!islower(infix[j])&& infix[j]!='(')
			{ 	 cerr<<"More than one operator connected."<<endl;
			  	 return false;
			}
		}
		//the left parenthese should be followed by either a letter or a '('
		if (c=='(')
		{
			do{j++;}while(isspace(infix[j])&& j<infix.size());
			if(infix[j]!='('&& !islower(infix[j]))
			{  	cerr<<"Wrong things after the left parentheses."<<endl;
				return false;
			}
		}

		// the right parenthese should not be followed by a letter or '('
		if(c==')')
		{
			do{j++;}while(isspace(infix[j])&& j<infix.size());
			if(islower(infix[j]) || infix[i]=='(')
			{	cerr<<"wrong things after ')'."<<endl;
				return false;			//operator right before ')'				
			}
		}

		 //check if contains not valid chars
		if(!islower(c) && !isspace(c) && !isOperator(c) && c!='(' && c!=')' )
		{
			cerr<<"This invalid char is "<< c <<"."<<endl;
			return false;
		}
	}
	return true;
}

int precedence(char op)
{
	switch (op)
	{
	 case '+':
	 case '-':
		return 1;
	 case '*':
	 case '/':
		return 2;
	 default:
		return 0;
	}
	return 0;
}

bool calculator(char op, int var1, int var2, int& ans)
{
	switch (op)
	{
	 case '+':
		ans= var1+var2; break;
	 case '-':
		ans= var1-var2; break;
	 case '*':
		ans= var1*var2; break;
	 case '/':
		if (var2==0)
			return false;
		ans= var1/var2; break;
	 default:
		return false;
	}
	return true;
}

bool toPostfix(string& infix, string& postfix)
{
	postfix="";
	stack<char> stackO;
	for (int i=0; i<infix.size(); i++)
	{
		char c = infix[i];
		switch (c)
		{
		 case 'a'...'z':
			postfix+= c; break;
		 case '(':
			stackO.push(c); break;
		 case ')':
			while(stackO.top()!='(' )
			{
			 postfix += stackO.top();	
			 stackO.pop();
			}
			stackO.pop();
			break;		//remove'('
		 case '+':
		 case '-':
		 case '*':
		 case '/':
			while(!stackO.empty()&& stackO.top()!='(' && precedence(c)<= precedence(stackO.top()))
			{
			 postfix += stackO.top();
			 stackO.pop();
			}
			stackO.push(c); 
			break;
		 case ' ':
		 	break;
		 default:
			cerr<<"stop at "<< c<<endl;
			return false;
			//break;
		}	
	}
	while (!stackO.empty())
	{
		postfix += stackO.top();
		stackO.pop(); 
	}
	return true;
}


void print(string str)
{
	for (int i=0; i<str.size(); i++)
		cerr<<str[i];
	cerr<<endl;
}

/*
int main()
{

	char vars[] = {'a','e','i','o','u','y','#'};
	int vals[] = { 3 , -9 , 6 , 2 , 4 , 1 };
	Map m;
	for (int k=0; vars[k] != '#'; k++)
		m.insert(vars[k],vals[k]);

	string pf;
	int answer;
	string test1 = "(e+a)/w";
	assert(isValid(test1));
	string test2 = "(a+e)/i";
	string test3 = "o + u * y"; 
	assert(toPostfix(test2,pf));
	assert(precedence(test2[2])==1);
	print(pf);
	assert(toPostfix(test3,pf));
	print(pf);
	pf = "";
	cerr<<"evaluate get return "<<evaluate("a+e",m,pf,answer)<<endl;
	assert(evaluate("a+e", m, pf, answer)==0 && pf == "ae+" && answer ==-6); 
	cerr<<"Pass the test!"<<endl;
	
}
*/

int main()
{
    char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
    int  vals[] = {  3,  -9,   6,   2,   4,   1  };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
	m.insert(vars[k], vals[k]);
    string pf;
    int answer;
    assert(evaluate("a+ e", m, pf, answer) == 0  &&
                            pf == "ae+"  &&  answer == -6);
    answer = 999;
    assert(evaluate("", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("()", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);
      // unary operators not allowed:
/*    assert(evaluate("-a", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a*b", m, pf, answer) == 2  &&
                            pf == "ab*"  &&  answer == 999);
    assert(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0  &&
                            pf == "yoau-*+"  &&  answer == -1);
    answer = 999;
    assert(evaluate("o/(y-y)", m, pf, answer) == 3  &&
                                   pf == "oyy-/"  &&  answer == 999);
    assert(evaluate(" a  ", m, pf, answer) == 0  &&
                            pf == "a"  &&  answer == 3);
    assert(evaluate("((a))", m, pf, answer) == 0  &&
                            pf == "a"  &&  answer == 3);
*/
    cout << "Passed all tests" << endl;
}
