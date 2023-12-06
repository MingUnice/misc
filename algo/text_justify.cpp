// 68. Text Justification

std::vector<std::string> fullJustify(std::vector<std::string> words, int width) {
  std::vector<std::string> ret;
  int len = words.size();
  std::vector<int> sizes(len);
  for (int i = 0; i < len; ++i)
    sizes[i] = words[i].size();
  int index = 0;
  while (index < len) {
    int w = sizes[index] + 1;
    std::string str = words[index];
    int i = 1;
    for (; i < len - index; ++i) {
      if (width - w < sizes[index + i])
        break;
      w += sizes[index + i] + 1;
    }
    --w;
    if (i == len - index) {
      for (int j = 1; j < i; ++j) {
        str += ' ';
        str += words[index + j];
      }
      str.resize(width, ' ');
      ret.push_back(str);
      break;
    }
    if (i != 1) {
      int remain = width - w;
      int space = remain / (i - 1) + 1;
      int left = remain % (i - 1);
      for (int j = 1; j < i; ++j) {
        for (int k = 0; k < space; ++k)
          str += ' ';
        if (j <= left) str += ' ';
        str += words[index + j];
      }
    }
    str.resize(width, ' ');
    ret.push_back(str);
    index += i;
  }
  return ret;
}

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.


// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.
// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
