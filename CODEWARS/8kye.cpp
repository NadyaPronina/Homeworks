int summation(int num){     //task 1
  int s = 0;
  for (int i = 1; i<= num; ++i){
    s+=i;
  }
  return s;
}


#include <vector>           //task2 (not given))0))

using namespace std; 

int count_sheep(vector<bool> arr) 
{
  int cnt = 0;
  for (int i = 0; i<arr.size(); ++i){
    if(arr[i] == true)
      ++cnt;
    else
      cnt +=0;
  }
  return cnt;
}


int basicOp(char op, int val1, int val2) {      //task2 could done easier and more optimal(
  int eql;
  switch (op){
      case '+':
        eql = val1 + val2;
        break;
      case '-':
        eql = val1 - val2;
        break;
      case '*':
        eql = val1 * val2;
        break;
      case '/':
        eql = val1 / val2;
        break;
      default:
      break;
  }
  return eql;
}


int centuryFromYear(int year)       //century from year
{
  int tmp = year % 100;
  if(tmp == 0)
    return year/100;
  else 
    return year/100 + 1;
}


#include <string>           //even ot odd

std::string even_or_odd(int number) 
{
  if(number % 2 == 0)
    return "Even";
  else
      return "Odd";
}


#include <string>       //reverse
using namespace std ; 

string reverseString (string str )
{
  string str1 = "";
  for(int i=str.size() - 1; i >= 0; --i){
    str1.push_back(str[i]);
  }
  return str1;
}



int opposite(int number)   //opposite number
{
  return (-1) * number;
}



#include <string>               //bool to word

std::string bool_to_word(bool value)
{
  if (value == true)
    return "Yes";
  else 
    return "No";
}



int twice_as_old(int dad, int son) {    //twice as old
  if (2 * son > dad){
    return 2*son - dad;
  }
  else 
    return dad - 2*son;
}
