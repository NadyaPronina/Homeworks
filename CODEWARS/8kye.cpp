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


#include <string>           //number to string

std::string number_to_string(int num) {
  std::string str = "";
  std::string str1 = "";
  int check;
  if (num < 0){
    str += "-";
    num *= (-1);
  }
  while(num > 0){
    check = num % 10;
      switch(check){
          case 0:
            str1+="0";
            break;
          case 1:
            str1+="1";
            break;
          case 2:
            str1+="2";
            break;
          case 3:
            str1+="3";
            break;
          case 4:
            str1+="4";
            break;
          case 5:
            str1+="5";
          break;
          case 6:
            str1+="6";
            break;
          case 7:
            str1+="7";
            break;
          case 8:
            str1+="8";
             break;
           case 9:
            str1+="9";
             break;
            default: break;}
     num /= 10;
}
  
  for(int i = str1.length()-1; i>=0; --i){
    str += str1[i];
  }
  return str;
}


#include <string>             //no_space

std::string no_space(const std::string& x){
  std::string str = "";
  for(int i = 0; i < x.length(); ++i){
    if(x[i] != ' '){
      str += x[i];
    }
  }
  return str;
}




