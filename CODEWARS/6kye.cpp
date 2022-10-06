// Count the smiley faces!
int countSmileys(std::vector<std::string> arr)
{
  int counter = 0;
  if(arr.empty())
    return counter;
  else {
    for(unsigned long idx = 0; idx < arr.size(); ++idx) {
        if ((arr[idx] == ":D")   || (arr[idx] == ":)")
           ||(arr[idx] == ":-D") || (arr[idx] == ":-)")
           || (arr[idx] == ":~D")|| (arr[idx] == ":~)")
           || (arr[idx] == ";D") || (arr[idx] == ";)")
           || (arr[idx] == ";-D")|| (arr[idx] == ";-)")
           || (arr[idx] == ";~D")|| (arr[idx] == ";~)"))
           ++counter;
    }
  }
     return counter;
}

//Find the missing term in an Arithmetic Progression
static long findMissing(std::vector<long> list){
if(list[1] - list[0] > list[2] - list[1])
  return list[0] + (list[2] - list[1]);
else {
  for(int i = 0; i < list.size() - 1; ++i)
  {
    if(list[i] + list[1] - list[0] != list[i+1])
    {
      return list[i] + list[1] - list[0];
    }
  }
}
}

//Create Phone Number
#include <string>

std::string createPhoneNumber(const int arr [10]){
std::string result = "(";
std::string tostr = "";
  for(int i = 0; i < 10; ++i)
  {
  switch(arr[i]){
  case 0: tostr += '0'; break;
  case 1: tostr += '1'; break;
  case 2: tostr += '2'; break;
  case 3: tostr += '3'; break;
  case 4: tostr += '4'; break;
  case 5: tostr += '5'; break;
  case 6: tostr += '6'; break;
  case 7: tostr += '7'; break;
  case 8: tostr += '8'; break;
  case 9: tostr += '9'; break;
  default: break;
  }
  }
  for(int i = 0; i < 3; ++i)
    result += tostr[i];
  result += ") ";
  for(int i = 3; i < 6; ++i)
    result += tostr[i];
  result += '-';
  for(int i = 6; i < 10; ++i)
    result += tostr[i];
  return result;
}

//Sum of Digits / Digital Root
int digital_root(int n)
{
int sum = 0;
bool flag = true;
  while(flag){
    while(n > 0) {
      sum += (n % 10);
      n /= 10;
    }

    if(sum > 9) {
      n = sum;
      sum = 0;
    } else {
      flag = !flag;
    }
  }
return sum;
}

//Does my number look big in this?
bool narcissistic( int value ){
  int counter = 0;
  int TMP = value;
  while(TMP > 0) {
    TMP /= 10;
    ++counter;
  }
  std::cout << "POV: " << counter << std::endl;

  TMP = value;
  
  int sum = 0;
  int dig = 0;
  int dign = 1;

  while(TMP > 0) {
    dign = 1;
    dig = TMP % 10;
    TMP /= 10;
    std::cout << "dig:" << dig << ", ";
    if(counter > 1) {
      for(int i = 0; i < counter; ++i)
      {
        dign *= dig;
      }

      sum+=dign;
      std::cout << dign << std::endl;
    } else {
      sum += dig;
    }
  }
  std::cout << "sum:" << sum << std::endl;
  if(sum == value)
    return true;
  else
    return false;
}

//Tribonacci Sequence
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result(n);
if (n==0){
    return result;
} else {
    result[0] += signature[0];
    result[1] += signature[1];
    result[2] += signature[2];

    for (int i = 3; i < n; ++i) {
        result[i] += result[i-3] + result[i-2] + result[i-1];
    }

    return result;
}
}

//Bit Counting
unsigned int countBits(unsigned long long n){
  int count = 0;

  while(n > 0) {
    if(n % 2 == 1)
      ++count;
    n /= 2;
  }
  return count;
}

//Duplicate Encoder
#include <string>

std::string duplicate_encoder(const std::string& word){

std::string strl = "";
char c;

    for (unsigned long i = 0; i < word.length(); ++i) {
        c = word[i];
        strl += std::tolower(c);
    }

    std::string res = "";

    for (unsigned long i = 0; i < word.length(); ++i)
    {
        if (std::count(strl.begin(), strl.end(), strl.at(i)) > 1)
            res += ")";
        else
            res += "(";
    }

    return res;
}

//A disguised sequence (I)
class HiddenSeq
{
    public:
    static unsigned long long fcn(int n) {
      return 1ull << n;
    }
};

//1/n- Cycle
int cycle(int n) {
    int res = 0;
    int del = 10;
    const int max = 1000000;

    //std::cout << "n: " << n << std::endl;

    do {
      ++res;
      del = del % n * 10;
      //std::cout << "del * 10 % n = " << del << std::endl;
      if (del == 10) return res;

    }  while (res < max);

    return -1;
}
