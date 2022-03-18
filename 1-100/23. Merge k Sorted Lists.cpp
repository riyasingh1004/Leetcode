// Time Complexity O(Nlog(k))
// k : number of LL
// N : number of nodes in the final LL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct CompareNode {
        bool operator()(ListNode* const & p1, ListNode* const & p2) {
            // return "true" if "p1" is ordered before "p2", for example:
            return p1->val > p2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        priority_queue<ListNode*,vector<ListNode*>,CompareNode> queue;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                queue.push(lists[i]);
            }
        }

        while (!queue.empty()) {
            tail->next = queue.top();
                queue.pop();
                tail = tail->next;

                if (tail->next) {
                    queue.push(tail->next);
                }
        }

        return dummy->next;
    }
};