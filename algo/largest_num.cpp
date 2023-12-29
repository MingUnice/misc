// 179. Largest Number

std::string largestNumber(std::vector<int> &nums)
{
  std::vector<std::string> strs;
  for (int i : nums)
    strs.emplace_back(std::to_string(i));
  std::sort(strs.begin(), strs.end(), [](const std::string &lhs,
                                         const std::string &rhs) {
    return lhs + rhs > rhs + lhs;
  });
  if (strs[0] == "0") return "0";
  std::string ret;
  for (const auto &s : strs)
    ret += s;
  return ret;
}

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.



// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"


// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
