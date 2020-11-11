	template<typename T>
	Node<T>* findLeastCommonAncestor(Node<T>* root, const T& p, const T& q) {
		
		while(root)
		{
			const auto& payload = root->val; 
			if(payload > p && payload > q){
				root = root->left;
			}
			else if(payload < p && payload < q){
				root = root->right;
			}
			else{
				return root;
			}
		}
		return root;		
	}