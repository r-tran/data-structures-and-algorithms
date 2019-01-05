namespace DSA.LinkedList
{
    public class Node<T>
    {
        internal Node<T> Next { get; set; }
        internal T Data { get; set; }

        public Node(T data)
        {
            Next = null;
            Data = data;            
        }
    }
}
