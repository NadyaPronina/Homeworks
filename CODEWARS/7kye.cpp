//Shortest Word
#include <iostream>

int find_short(std::string str)
{
    int min = str.length();
    int len = 0;
    char c;
    
    for (int i = 0; i < str.length(); ++i)
    {
        c = str[i];
        if (c != ' ')
            len += 1;
        else {
            if (len > 0 && min > len)
                min = len;
            len = 0;
        }
    }

    if (min > len) return len;

    return min;
}

//Are the numbers in order?
bool isAscOrder(std::vector<int> arr)
{
    for(int i = 0; i < arr.size() - 1; ++i)
    {
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

//Anagram Detection
#include <string>
bool isAnagram(std::string test, std::string original){
  if(test.length() != original.length()) return false;
  
  int Arr[256] = {0};
  char t, o;
  
  for(unsigned long i = 0; i < test.length(); ++i)
  {
    t = test[i];
    o = original[i];
    
    ++Arr[int(t)];
    //std::cout << Arr[int(t)] << ", : " << t << "\n";
    --Arr[int(o)];
    //std::cout << Arr[int(o)] << ", : " << o << "\n";
  }
  //std::cout << std::endl;
  int del = int('a') - int('A');
  //std::cout << "delta: " << del << std::endl;
  
  for(int i = int('A'); i <= int('Z') ; ++i)
  {
    if(Arr[i] + Arr[i + del] != 0)
    {
      //std::cout << Arr[i] << ", : " << char(i) << "\n";
      //std::cout << Arr[i + del] << ", : " << char(i + del) << "\n";
      return false;
    }
  }
  return true;
}

//Isograms
bool is_isogram(std::string str) {
  int Arr[256] = {0};
  
  char c;
  for(unsigned long i = 0; i < str.length(); ++i)
  {
    c = str[i];
    ++Arr[int(c)];
    std::cout << Arr[int(c)] << ", ";
  }
  std::cout << std::endl;

  int del = int('a') - int('A');
  std::cout << "delta: " << del << std::endl;
 
  for(int i = int('A'); i < int('Z'); ++i)
  {
    if(Arr[i] + Arr[i + del] > 1)
    {
      return false;
    }
  }
  return true;
}

//Complementary DNA
#include <string>

std::string DNAStrand(const std::string& dna)
{
  std::string res(dna.length(), ' ');
  
  for(unsigned long i = 0; i < dna.length(); ++i)
  {
    if(dna[i] != 'A' && dna[i] != 'T' && dna[i] != 'G' && dna[i] != 'C')
    {
      res[i] = dna[i];
    } else {
      if(dna[i] == 'A') res[i] = 'T';
      if(dna[i] == 'T') res[i] = 'A';
      if(dna[i] == 'C') res[i] = 'G';
      if(dna[i] == 'G') res[i] = 'C';
    }
    
  }
  return res;
}

//Exes and Ohs
bool XO(const std::string& str)
{
  int Arr[256];
  Arr[int('X')] = Arr[int('x')] = Arr[int('O')] = Arr[int('o')] = 0;
  char c;
  
  for(unsigned long i = 0; i < str.length(); ++i)
  {
    c = str[i];
    ++Arr[int(c)];
  }
  
  int sum_x = Arr[int('X')] + Arr[int('x')];
  int sum_o = Arr[int('O')] + Arr[int('o')];
  std::cout << "o: " << sum_o << ", x: " << sum_x << std::endl;

  if(sum_x - sum_o == 0)
    return true;
  else
    return false;
}

//Sum of two lowest positive integers
#include <vector>

long sumTwoSmallestNumbers(std::vector<int> numbers){
    long min = numbers[0], pmin = numbers[1];
    //min = (pmin<min)?pmin:min;
    if(pmin<min) std::swap(min,pmin);
    for(int i = 2; i < numbers.size(); ++i){
      if(numbers[i] <= min) {
        std::swap(min, pmin);
        min = numbers[i];
      }
      else if(numbers[i] < pmin) 
        pmin = numbers[i];
    }
  std::cout<<pmin<<" min = "<<min<<std::endl;
    return min + pmin;
}

//Get the Middle Character
std::string get_middle(std::string input)
{
  std::string result;
  if(input.length() % 2 == 0){
    result += input[input.length()/2 - 1];
    result += input[input.length()/2];
    return result;
  }
  else {
    result += input[input.length()/2];
    return result;
  }
}

//Reverse words
std::string reverse_words(std::string str)
{
  std::string rev;
  std::string result;
  for (int i = 0; i < str.length(); ++i){
    if (str[i] != ' ')
      rev = str[i] + rev;
    else {
      result += rev;
      result += ' ';
      rev = "";
    }
  }
  result += rev;
  return result;
}

//You're a square!
bool is_square(int n)
{
  for(int i = 0; i < n / 2 + 1; ++i)
    if(i * i == n) return true;
  return false;
}
