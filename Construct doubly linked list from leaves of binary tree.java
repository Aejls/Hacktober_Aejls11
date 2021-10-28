class Tree{
    
    Node prev,next,head;
    public Node convertToDLL(Node root)
    {   
       prev=null;
       next=null;
       head=null;
       construct(root);
       return head;
    }
    public Node construct(Node root){
        if(root==null) return null;
        if(root.left==null&&root.right==null){
            if(head==null){
                head=new Node(root.data);
                prev=head;
            }
            else{
                next=new Node(root.data);
                prev.right=next;
                next.left=prev;
                prev=next;
            }
            return null;
        }
        root.left=construct(root.left);
        root.right=construct(root.right);
        return root;
    }
}
