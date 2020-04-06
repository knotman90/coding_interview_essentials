template<typename T>
Node<T>* detect_cycle_linear_time(Node<T> *head)
{
	using Node_ptr = Node<T>*;	
	std::unordered_set<Node_ptr> visited;

	while(head)
	{
		//has the current node already been visited?
		if(visited.find(head)!= visited.end())
			return head;
		//if not, then remember that we did now
		visited.insert(head);
		//advance one node in the list
		head = head->next;
	}
	return nullptr;
}