#include "OA2.h"


void InitializeMatrix(vector< vector<int> > &matrix, int nums[][4])
{
    for(unsigned i = 0; i < matrix.size(); i++)
    {
        for(unsigned j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j] = nums[i][j];
        }
    }
}


void PrintMatrix(vector< vector<int> > matrix)
{
    int m = matrix.size();
    if(!m)
    {
        cout << "Empty Vector" << endl;
        return;
    }
    int n = matrix[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;

}


vector< vector<int> > RotateMatrix270(vector< vector<int> > matrix)
{
    int m = matrix.size();
    if(!m)
        return matrix;
    int n = matrix[0].size();
    vector< vector<int> > rotatedMatrix(n, vector<int> (m, 0));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            rotatedMatrix[j][m-i-1] = matrix[i][j];
        }
    }
    return rotatedMatrix;

}


vector< vector<int> > RotateMatrix(vector< vector<int> > matrix, bool flag)
{
    int m = matrix.size();
    if(!m)
        return matrix;
    int n = matrix[0].size();

    vector< vector<int> > rotatedMatrix(n, vector<int> (m, 0));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(flag)
                rotatedMatrix[n-j-1][i] = matrix[i][j];
            else
                rotatedMatrix[j][m-i-1] = matrix[i][j];
        }
    }
    return rotatedMatrix;

}


int MinPathSum(vector< vector<int> > grid)
{
    int m = grid.size();
    if(!m)
        return 0;
    int n = grid[0].size();

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 and j == 0)
                grid[i][j] = grid[i][j];
            else if(i == 0 and j != 0)
                grid[i][j] += grid[i][j-1];
            else if(j == 0 and i != 0)
                grid[i][j] += grid[i-1][j];
            else
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}


int GreatestCommonDividerNaive(int a, int b)
{
    int gcd = 1;
    for(int i = 1; i <= a && i <= b; i++)
    {
        if(a%i == 0 && b%i == 0)
            gcd = i;
    }
    return gcd;
}


int GreatestCOmmonDividerEuclid(int a, int b)
{
    return b == 0 ? a : GreatestCOmmonDividerEuclid(b, a%b);
}

/** Find min path sum from root to leaf(!), path = {head} + left path, if left sum is smaller
 *
 * head: root node pointer
 * path: path vector
 * return path sum
 *
 */
int MinTreePathSum(TreeNode *head)
{
    if(!head)  // head is NULL
        return 0;
    else if(!(head->left) && head->right)  // only head->left is NULL
        return head->val+MinTreePathSum(head->right);
    else if(!(head->right) && head->left)  // only head->right is NULL
        return head->val+MinTreePathSum(head->left);
    else
        return head->val+min(MinTreePathSum(head->left), MinTreePathSum(head->right));  // none of left and right are NULL
}


ListNode *ReverseHalfLinkedList(ListNode *head)
{
    if(!head || !head->next || !head->next->next)
        return head;
    ListNode *p = head, *q = head, *preTail;
    // Get middle node as new head
    while(p && p->next)
    {
        p = p->next->next;
        if(p && !p->next)
            preTail = q;
        q = q->next;
        if(p && (p->next) && !p->next->next)
            preTail = q;
    }

    ListNode *r = NULL;
    ListNode *s = NULL;
    while(q)
    {
        s = q->next;
        q->next = r;
        r = q;
        q = s;
    }
    preTail->next = r;
    return head;
}


ListNode *InsertCyclicLinkedList(ListNode *start, int x)
{
    ListNode *pNewNode = new ListNode(x);
    // 1. List is Null: new ListNode(x), points to itself
    if(!start)
    {
        pNewNode->next = pNewNode;
        return pNewNode;
    }
    // 2. List is not Null: Find its minimum node
    ListNode *pCurrent = start, *pNext = start->next;
    while(pNext != start && pCurrent->val <= pNext->val)
    {
        pCurrent = pCurrent->next;
        pNext = pNext->next;
    }
    // 3. Find the correct location to insert x, if x < 1st node
    ListNode *pMinNode = pNext;
    pCurrent = pMinNode;
    pNext = pCurrent->next;
    while(!(pCurrent->val <= x && x <= pNext->val) && pNext != pMinNode)
    {
        pCurrent = pCurrent->next;
        pNext = pNext->next;
    }
    pCurrent->next = pNewNode;
    pNewNode->next = pNext;
    return pNewNode;
}


bool IsSameTree(TreeNode *h1, TreeNode *h2)
{
    if(!h1 || !h2)
        return h1 == h2;
    else
        return (h1->val == h2->val) && IsSameTree(h1->left, h2->left) && IsSameTree(h1->right, h2->right);
}


bool IsSubTree(TreeNode *r1, TreeNode *r2)
{
    if(IsSameTree(r1, r2))
        return true;
    else
    {
        return ((r1->left) && IsSubTree(r1->left, r2)) || ((r1->right) && IsSubTree(r1->right, r2));
    }
}


int IsValidParenthesis(string p)
{
    stack<char> s;
    for(unsigned i = 0; i < p.size(); i++)
    {
        if(p[i] == '(')
            s.push(p[i]);
        else if(p[i] == ')')
        {
            if(s.top() == '(')
                s.pop();
            else
                s.push(p[i]);
        }
    }
    if(!s.size())
        return p.size();
    else
        return -1;

}


bool SearchMazeDFS(vector< vector<int> > m, unsigned i, unsigned j)
{
    if(m[i][j] == 0 || i < 0 || i >= m.size() || j < 0 || j >= m[0].size())
        return false;
    if(m[i][j] == 9)
        return true;
    if(m[i][j] == 1)
    {
        m[i][j] = 0;
        return SearchMazeDFS(m, i+1, j) || SearchMazeDFS(m, i, j+1) || SearchMazeDFS(m, i, j-1) || SearchMazeDFS(m, i, j+1);
    }
    return false;
}


int Maze(vector< vector<int> > m)
{
    if(m.size() == 0)
        return 0;
    else
        return SearchMazeDFS(m, 0, 0) ? 1 : 0;

}


vector<int> DayChange(vector<int> cells, int days)
{
    if(cells.size() == 0)
        return cells;
    vector<int> newCells = cells;
    for(int i = 0; i < days; i++)
    {
        for(unsigned j = 0; j < cells.size(); j++)
        {
            if(j == 0)
                newCells[j] = 0 ^ cells[j+1];
            else if(j == cells.size()-1)
                newCells[j] = cells[j-1] ^ 0;
            else
                newCells[j] = cells[j-1] ^ cells[j+1];
        }
        cells = newCells;
    }
    return newCells;
}


int LRU_Cache(vector<int> data, unsigned capacity)
{
    int missCount = 0;
    list<int> LRU(0, 0);

    for(unsigned i = 0; i < data.size(); i++)
    {
        bool found = false;
        for(list<int>::iterator it = LRU.begin(); it != LRU.end(); it++)
        {
            if(*it == data[i])
                found = true;
        }
        if(found)
        //if(find(LRU.begin(), LRU.end(), data[i]) != LRU.end())
        {
            LRU.remove(data[i]);
            LRU.push_back(data[i]);
        }
        else
        {
            missCount += 1;
            if(LRU.size() == capacity)
            {
                LRU.pop_front();
            }
            LRU.push_back(data[i]);
        }
    }
    return missCount;
}


void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


float ShortestJobFirst(vector<int> arrivalTime, vector<int> exeTime)
{
    // Sort executionTime in ascending order, then apply FCFS scheduling
    int n = exeTime.size();
    if(!n)
        return 0;
    int startTime = arrivalTime[0], totalExeTime = 0, totalWaitTime = 0, k, temp1, temp2;
    for(int i = 0; i < n-1; i++)
    {
        k = i;
        for(int j = i+1; j < n; j++)
        {
            if(exeTime[j] < exeTime[k])
                k = j;
        }

        temp1 = exeTime[i];
        exeTime[i] = exeTime[k];
        exeTime[k] = temp1;

        temp2 = arrivalTime[i];
        arrivalTime[i] = arrivalTime[k];
        arrivalTime[k] = temp2;

    }

    for(int i = 0; i < n; i++)
    {
        if(totalExeTime <= arrivalTime[i])
            totalWaitTime += 0;
        else
            totalWaitTime += startTime+totalExeTime-arrivalTime[i];
        totalExeTime += exeTime[i];
    }
    return float(totalWaitTime)/float(n);

}


int VectorSum(vector<int> exeTime)
{
    int totalRemainExeTime = 0;
    for(unsigned i = 0; i < exeTime.size(); i++)
    {
        totalRemainExeTime += exeTime[i];
    }
    return totalRemainExeTime;
}


float RoundRobin(vector<int> arrivalTime, vector<int> exeTime, int q)
{
    int totalWaitTime = 0, totalExeTime = 0, startTime = arrivalTime[0], totalRemainExeTime = VectorSum(exeTime);
    while(totalRemainExeTime)
    {
        for(unsigned i = 0; i < arrivalTime.size(); i++)
        {
            if(exeTime[i] >= q)
            {
                totalWaitTime += startTime+totalExeTime-arrivalTime[i];
                totalExeTime += q;
                arrivalTime[i] = startTime+totalExeTime;
                exeTime[i] -= q;
            }
            else if(exeTime[i] > 0)
            {
                totalWaitTime += startTime+totalExeTime-arrivalTime[i];
                totalExeTime += exeTime[i];
                arrivalTime[i] = startTime+totalExeTime;
                exeTime[i] = 0;
            }
        }
        totalRemainExeTime = VectorSum(exeTime);
    }
    return float(totalWaitTime)/float(arrivalTime.size());
}
