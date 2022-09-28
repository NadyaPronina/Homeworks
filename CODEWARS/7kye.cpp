std::string reverse_words(std::string str)   // reverse words
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



std::string get_middle(std::string input)         //get middle
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


