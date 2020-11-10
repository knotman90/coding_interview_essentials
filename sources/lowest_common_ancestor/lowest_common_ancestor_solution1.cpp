	private static TreeNode findLeastCommonAncestor(TreeNode root, int i, int j) {
		while(true){
			if(root.val>i && root.val>j){
				root = root.left;
			}
			else if(root.val<i && root.val<j){
				root = root.right;
			}
			else{
				return root;
			}
		}		
	}