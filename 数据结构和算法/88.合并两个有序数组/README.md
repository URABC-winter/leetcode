## 解题思路
### 倒序双指针
1. 创建三个指针，1为nums1非0末尾，2为nums2末尾，3为nums1末尾.</br>
2. 当nums2大于等于0时，比较nums1和nums2大小，将较大值赋给nums1末尾指针，并移动nums1有效值指针或nums2指针。</br>
### 暴力解法
1. 去除nums1中0，将nums2中的元素全部赋值给nums1。
2. 冒泡排序nums1.