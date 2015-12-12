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


int MinTreePathSumStackoverflow(TreeNode *head, list<TreeNode *> &path)
{
    if(!head)  // head is NULL
        return 0;
    else if(!(head->left) && head->right)  // only head->left is NULL
    {
        list<TreeNode *> pathTemp;
        int val = head->val+MinTreePathSumStackoverflow(head->right, pathTemp);
        pathTemp.push_front(head);
        path.merge(pathTemp);
        return val;
    }
    else if(!(head->right) && head->left)  // only head->right is NULL
    {
        list<TreeNode *> pathTemp;
        int val = head->val+MinTreePathSumStackoverflow(head->left, pathTemp);
        pathTemp.push_front(head);
        path.merge(pathTemp);
        return val;
    }
    else
    {
        int vl, vr, val;
        list<TreeNode *> pathTempL, pathTempR;
        vl = MinTreePathSumStackoverflow(head->left, pathTempL);
        vr = MinTreePathSumStackoverflow(head->right, pathTempR);
        if(vl < vr)
        {
            val = vl;
            pathTempL.push_front(head);
            path.merge(pathTempL);
        }
        else
        {
            val = vr;
            pathTempR.push_front(head);
            path.merge(pathTempR);
        }
        return head->val + val;
    }
}


ListNode *ReverseHalfLinkedList(ListNode *head)
{
    ListNode *p = head, *q = head;
    // Get middle node as new head
    while(p && p->next)
    {
        p = p->next->next;
        if(!p->next || !p->next->next)
            ListNode *preTail = q;
        q = q->next;
    }
    ListNode *r = q->next;
    ListNode *s;
    while()
    {
        s = r.next;
        r.next = q;

    }

    return NULL;
}
