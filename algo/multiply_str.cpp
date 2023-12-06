// 43. Multiply Strings

string multiply(string num1, string num2)
{
  const size_t size1 = num1.size(), size2 = num2.size();
  int k = 8;
  unsigned long long powerk = 100000000;
  int l1 = size1 / k + (size1 % k ? 1 : 0);
  int l2 = size2 / k + (size2 % k ? 1 : 0);
  unsigned long long nums1[l1], nums2[l2];
  for (int i = 0; i < l1; ++i) {
    int offset = size1 - k * (i + 1);
    if (offset < 0)
      nums1[i] = std::stoull(num1.substr(0, size1 % k));
    else
      nums1[i] = std::stoull(num1.substr(offset, k));
  }
  for (int i = 0; i < l2; ++i) {
    int offset = size2 - k * (i + 1);
    if (offset < 0)
      nums2[i] = std::stoull(num2.substr(0, size2 % k));
    else
      nums2[i] = std::stoull(num2.substr(offset, k));
  }
  unsigned long long values[l1 + l2];
  memset(values, 0, sizeof(values));
  for (int i = 0; i < l1; ++i) {
    for (int j = 0; j < l2; ++j) {
      unsigned long long res = nums1[i] * nums2[j];
      values[i + j] += res % powerk;
      values[i + j + 1] += res / powerk;
    }
  }
  for (int i = 0; i < l1 + l2 - 1; ++i) {
    if (values[i] > powerk) {
      values[i + 1] += values[i] / powerk;
      values[i] = values[i] % powerk;
    }
  }
  std::string ret;
  int vsize = 0;
  for (int i = l1 + l2 - 1; i >= 0; --i) {
    if (values[i] > 0) {
      vsize = i;
      break;
    }
  }
  for (int i = 0; i <= vsize; ++i) {
    std::string tmp = std::to_string(values[i]);
    if (i != vsize && k > tmp.size())
      tmp = std::string(k - tmp.size(), '0') + tmp;
    ret = tmp + ret;
  }
  return ret;
}



// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
