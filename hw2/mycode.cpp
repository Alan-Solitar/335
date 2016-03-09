   int CalculateDepth(BinaryNode* t, int current_depth) {


       if(t==nullptr) {
       	return 0;
       }
     
        return current_depth + CalculateDepth(t->left_,current_depth+1)+ CalculateDepth(t_right_,current_depth+!)
    }