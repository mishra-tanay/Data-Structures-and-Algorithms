struct node {
	ll sum, prefixsum, suffixsum, maxsum;
	node(){
		sum=prefixsum=suffixsum=maxsum=0;
	}
};
node segtree[4 * MAXN];
ll arr[MAXN];
node merge(node a, node b) {
	node par;
	par.sum = a.sum + b.sum;
	par.prefixsum = max(a.prefixsum, a.sum + b.prefixsum);
	par.suffixsum = max(b.suffixsum, b.sum + a.suffixsum);
	par.maxsum =    max(par.prefixsum,par.suffixsum);
	par.maxsum =    max(par.maxsum,max(a.maxsum,b.maxsum));
	par.maxsum =    max(par.maxsum,a.suffixsum+b.prefixsum);
	return par;
}
void build(int curr, int low, int high)
{
	if (low == high) {
		segtree[curr].sum = arr[low];
		segtree[curr].prefixsum = arr[low];
		segtree[curr].suffixsum = arr[low];
		segtree[curr].maxsum = arr[low];
	}
	else {
		int mid = (low + high) / 2;
		build(2 * curr, low, mid);
		build(2 * curr + 1, mid + 1, high);
		segtree[curr] = merge(segtree[2 * curr], segtree[2 * curr + 1]);
	}
}

void update(int curr, int low, int high, int idx, int value) 
{ 
    if (low == high) { 
        segtree[curr].sum = value; 
        segtree[curr].prefixsum = value; 
        segtree[curr].suffixsum = value; 
        segtree[curr].maxsum = value; 
    } 
    else { 
  
        int mid = (low + high) / 2; 
        if (idx <= mid) 
            update(2 * curr , low, mid, idx, value); 
        else
            update(2 * curr +1 , mid + 1, high, idx, value); 
        segtree[curr]=merge(segtree[2*curr],segtree[2*curr +1]);
    } 
}


node query(int curr, int low,  int high, int l, int r) 
{ 
    node result; 
    result.sum = result.prefixsum =  result.suffixsum =  result.maxsum = INT_MIN; 

    if (r < low || high < l) 
        return result; 
  
    if (l <= low && high <= r) 
        return segtree[curr]; 
  
    int mid = (low + high) / 2; 
 
    if (l > mid) 
        return query(2 * curr + 1,mid + 1, high, l, r);      
    if (r <= mid) 
        return query(2 * curr ,low, mid, l, r); 
  
    node left = query (2 * curr,low, mid, l, r); 
    node right = query(2 * curr + 1, mid + 1, high, l, r);
    result=merge(left,right);
    return result; 
}