void updateValueUtil(ll *st, int ss, int se, int index, int new_val, int si)
{
    //base cases
    if (index < ss || index > se) return;
    if (se == ss) {
        st[si] = new_val;
        return;
    }
    
    //if the input index is in range of this node then we update
    //the value of the node and its children.
    int mid = getMid(ss, se);
    if (index <= mid)
        updateValueUtil(st, ss, mid, index, new_val, 2 * si + 1);
    else
        updateValueUtil(st, mid + 1, se, index, new_val, 2 * si + 2);

    st[si] = LCM(st[si * 2 + 1], st[si * 2 + 2]);
    return;
}

//Function to update a value in input array and segment tree.
//It uses updateValueUtil() to update the value in segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    //base case for invalid input.
    if (index < 0 || index > n - 1) {
        
        return;
    }
    arr[index] = new_val;
    
    //updating the value of nodes in segment tree.
    updateValueUtil(st, 0, n - 1, index, new_val, 0);
}

//recursive function to get LCM of given range of array indexes.
ll getLCMUtil(ll *st, int ss, int se, int qs, int qe, int si)
{
    //if segment of this node is a part of given range, we return st[si].
    if (qs <= ss && qe >= se) 
    return st[si];
    
    //if segment of this node is outside the given range, we return 1.
    if (se < qs || ss > qe)
    return 1;
    
    //if a part of this segment overlaps with the given range, we call
    //the function recursively for the children nodes.
    int mid = getMid(ss, se);
    return LCM(getLCMUtil(st, ss, mid, qs, qe, 2 * si + 1),
               getLCMUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
}

//Function to find LCM of given range.
ll getLCM(ll *st, int *arr, int n, int qs, int qe) 
{
    //base case for invalid input.
    // if (qs < 0 || qe > n - 1 || qs > qe) {
    //     return -1;
    // }

    return getLCMUtil(st, 0, n - 1, qs, qe, 0);
}
