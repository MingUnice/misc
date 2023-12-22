// 801. Minimum Swaps To Make Sequences Increasing


int minSwap(vector<int>& A, vector<int>& B) {
  const int n = A.size();

  vector<int> keep(n, INT_MAX);
  vector<int> swap(n, INT_MAX);

  keep[0] = 0;
  swap[0] = 1;

  for (int i = 1; i < n; ++i) {
    if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
      // Good case, no swapping needed.
      keep[i] = keep[i - 1];

      // Swapped A[i - 1] / B[i - 1], swap A[i], B[i] as well
      swap[i] = swap[i - 1] + 1;
    }

    if (B[i] > A[i - 1] && A[i] > B[i - 1]) {
      // A[i - 1] / B[i - 1] weren't swapped.
      swap[i] = min(swap[i], keep[i - 1] + 1);

      // Swapped A[i - 1] / B[i - 1], no swap needed for A[i] / B[i]
      keep[i] = min(keep[i], swap[i - 1]);
    }
  }

  return min(keep.back(), swap.back());
}

// You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

// An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].



// Example 1:

// Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
// Output: 1
// Explanation:
// Swap nums1[3] and nums2[3]. Then the sequences are:
// nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
// which are both strictly increasing.
// Example 2:

// Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
// Output: 1
