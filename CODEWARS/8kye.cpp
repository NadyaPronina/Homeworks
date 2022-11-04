int summation(int num){     //task 1
    return num * (num + 1) / 2;  //
}


#include <vector>           //task2 (not given))0))   я нажала на след kata и мне дало такое задание, оказывается оно выкидывает рандомное, не найду его условие
                           //есть подозрение, что смысла немного в +=0 ))
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


#include <string>       //redone
using namespace std ; 

string reverseString (string str )
{
char swapper;

  for(int i=0; i < str.length()/2; ++i) {
    swapper = str[i];
    str[i] = str[str.length() - 1- i];
    str[str.length() - 1- i] = swapper;
  }
  return str;
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
  int check;
  char swapper;
  char c;
    
  bool hasminus = false;
  if (num < 0){
      hasminus = true;
    num *= (-1);
  }

  while(num > 0){
    check = num % 10;
    c = check + 48;
    num /= 10;
    str += c;
}
    if(hasminus) str += '-';
    
    for(int i=0; i < str.length()/2; ++i) {
        swapper = str[i];
        str[i] = str[str.length() - 1- i];
        str[str.length() - 1- i] = swapper;
    }
    std::cout << str << std::endl;
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




