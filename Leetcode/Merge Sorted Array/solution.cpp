/* Approach->
(1) Create a MinHeap using priority queue.
(2) Push all elements of nums1 and nums2 in that priority queue, so this has automatically sorted the queue.
(3) As we were asked to modify nums1 so clear old nums1 and then push all elements of priority queue into nums1.
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;  // minheap created
        for (int i = 0; i < m; i++)
        {
            pq.push(nums1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            pq.push(nums2[i]);
        }
        nums1.clear();
        for (int i = 0; i < m + n; i++)
        {
            nums1.push_back(pq.top());
            pq.pop(); // remove top element each time so that you get new top element in next iteration.
        }
    }
};